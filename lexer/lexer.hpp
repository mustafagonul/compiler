#ifndef LEXER_LEXER_HPP
#define LEXER_LEXER_HPP

#include <iosfwd>
#include <vector>
#include "lexer/token.hpp"


namespace lexer {

  class Lexer {
  public:
    Lexer();

    // TODO deleted functions

  public:
    bool process(std::istream &);

    unsigned    tokenCount() const;
    TokenClass  tokenClass(unsigned) const;
    std::string tokenClassString(unsigned) const;
    std::string tokenLexeme(unsigned) const;

  private:
    bool process(std::string const &);

  private:
    std::vector<Token> tokens;

  };

}


#endif // LEXER_LEXER_HPP
