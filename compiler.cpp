#include "lexer/lexer.hpp"
#include <fstream>
#include <iostream>

int main()
{
  std::ifstream file("test");
  lexer::Lexer lexer;
  lexer.process(file);

  unsigned count = lexer.tokenCount();

  for (unsigned i = 0; i < count; ++i) {
    std::cout << lexer.tokenLexeme(i) << " = " << lexer.tokenClassString(i) << std::endl;
  }

  return 0;
}
