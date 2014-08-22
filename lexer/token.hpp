#ifndef LEXER_TOKEN_HPP
#define LEXER_TOKEN_HPP

#include "lexer/tokenclass.hpp"
#include <string>


namespace lexer {

  class Token {
  private:
    Token(TokenClass, std::string const &);

  public:
    static Token match(std::string const &);

  public:
    TokenClass tokenClass() const;
    std::string tokenClassString() const;
    std::string const &lexeme() const;

  private:
    TokenClass  m_tokenClass;
    std::string m_lexeme;
  };

}


#endif // LEXER_TOKEN_HPP
