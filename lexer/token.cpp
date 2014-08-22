#include "lexer/token.hpp"
#include <boost/regex.hpp>


namespace lexer {


Token::Token(TokenClass tc, std::string const &l)
  : m_tokenClass(tc)
  , m_lexeme(l)
{
}

Token Token::match(std::string const &str)
{
  static boost::regex keyword("int|void|type");
  //boost::regex identifier("[_a-zA-Z][_a-zA-Z0-9]*");
  static boost::regex identifier("[_[:alpha:]][_[:alnum:]]*");
  static boost::regex punctuator("["
                                    "\\{"
                                    "\\}"
                                    "\\<"
                                    "\\>"
                                    "\\("
                                    "\\)"
                                    "\\["
                                    "\\]"
                                    ";"
                                    "="
                                 "]");
  static boost::regex constant("[1-9][0-9]*"          "|"
                               "0[0-7]*"              "|"
                               "0x[0-9a-fA-F]*");

  if (boost::regex_match(str, keyword))
    return Token(TokenClass::Keyword, str);

  if (boost::regex_match(str, identifier))
    return Token(TokenClass::Identifier, str);

  if (boost::regex_match(str, constant))
    return Token(TokenClass::Constant, str);

  if (boost::regex_match(str, punctuator))
    return Token(TokenClass::Punctuator, str);

  return Token(TokenClass::None, str);
}

TokenClass Token::tokenClass() const
{
  return m_tokenClass;
}

std::string Token::tokenClassString() const
{
  switch (tokenClass()) {
  case TokenClass::Keyword: return "Keyword";
  case TokenClass::Identifier: return "Identifier";
  case TokenClass::Constant: return "Constant";
  case TokenClass::StringLiteral: return "StringLiteral";
  case TokenClass::Punctuator: return "Punctuator";
  default: return "None";
  }
}

std::string const &Token::lexeme() const
{
  return m_lexeme;
}


} // lexer
