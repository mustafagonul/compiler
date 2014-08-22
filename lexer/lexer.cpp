#include "lexer/lexer.hpp"
#include <iostream>


namespace lexer {


Lexer::Lexer()
  : tokens()
{
}

bool Lexer::process(std::istream &is)
{
  while (is) {
    std::string str;
    is >> str;

    if (str.empty())
      continue;

    if (process(str) == false)
      return false;
  }

  return true;
}

bool Lexer::process(std::string const &str)
{
  if (str.empty())
    return true;

  if (str.length() == 1) {
    auto match = Token::match(str);
    if (match.tokenClass() == TokenClass::None)
      return false;

    tokens.push_back(match);
    return true;
  }

  for (unsigned i = 1; i < str.length(); ++i) {
     auto substr1 = str.substr(0, i);
     auto substr2 = str.substr(0, i + 1);

     auto match1 = Token::match(substr1);
     auto match2 = Token::match(substr2);

     if (match1.tokenClass() == TokenClass::None)
       return false;

     if (match1.tokenClass() != TokenClass::None &&
         match2.tokenClass() == TokenClass::None) {
       tokens.push_back(match1);
       return process(str.substr(i));
     }

     if (substr2 == str) {
       tokens.push_back(match2);
       return true;
     }
  }

  return false;
}

unsigned Lexer::tokenCount() const
{
  return tokens.size();
}

TokenClass Lexer::tokenClass(unsigned i) const
{
  return tokens[i].tokenClass();
}

std::string Lexer::tokenClassString(unsigned i) const
{
  return tokens[i].tokenClassString();
}

std::string Lexer::tokenLexeme(unsigned i) const
{
  return tokens[i].lexeme();
}


} // lexer
