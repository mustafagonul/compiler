#ifndef LEXER_TOKENCLASS_HPP
#define LEXER_TOKENCLASS_HPP

#include <string>


namespace lexer {

  enum class TokenClass {
    Keyword,
    Identifier,
    Constant,
    StringLiteral,
    Punctuator,
    None,
  };

}


#endif // LEXER_TOKENCLASS_HPP
