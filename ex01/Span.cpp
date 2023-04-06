#include "Span.hpp"

#include <exception>
#include <vector>

Span::Span(int capacity) : capacity(capacity), numbers(std::vector<int>()) {}
Span::~Span() {}
Span::Span(const Span &copy) : capacity(copy.capacity), numbers(copy.numbers) {}
Span &Span::operator=(const Span &copy) {
  this->numbers = copy.numbers;
  this->capacity = copy.capacity;
  return *this;
}

void Span::addNumber(int number) {
  if (this->numbers.size() == (unsigned int)this->capacity)
    throw std::exception();
  this->numbers.push_back(number);
}
int Span::shortestSpan() const {
  if (this->numbers.size() < 2)
    throw std::exception();
  std::vector<int> copy = this->numbers;
  std::sort(copy.begin(), copy.end());
  bool isFirst = true;
  int last;
  int result;
  for (std::vector<int>::iterator it = copy.begin(); it != copy.end();) {
    if (!isFirst) {
      int difference = *it - last;
      if (result > difference)
        result = difference;
      last = *it;
      it++;
    } else {
      isFirst = false;
      last = *it;
      it++;
      result = *it - last;
    }
  }
  return result;
}

int Span::longestSpan() const {
  if (this->numbers.size() < 2)
    throw std::exception();
  std::vector<int> copy = this->numbers;
  int max = this->numbers[0];
  int min = this->numbers[0];
  for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++) {
    if (max < *it)
      max = *it;
    if (min > *it)
      min = *it;
  }
  return max - min;
}
