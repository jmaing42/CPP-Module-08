#include <cstdlib>
#include <iostream>

#include "Span.hpp"

static void test(int count) {
  Span sp(count);
  for (int i = 0; i < count; i++) {
    sp.addNumber(rand() % 4242);
  }
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

int main() {
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  test(4);
  test(2);
  test(42);
  test(4242);
}
