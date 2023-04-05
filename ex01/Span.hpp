#ifndef EX01_SPAN_TPP_INCLUDED
#define EX01_SPAN_TPP_INCLUDED

#include <vector>

class Span {
private:
  int capacity;
  std::vector<int> numbers;

public:
  Span(int length = 42);
  ~Span();
  Span(const Span &copy);
  Span &operator=(const Span &copy);

  void addNumber(int number);
  int shortestSpan() const;
  int longestSpan() const;
};

#endif
