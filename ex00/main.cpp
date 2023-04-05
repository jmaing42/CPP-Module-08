#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <queue>
#include <stack>
#include <vector>

#include "easyfind.tpp"

template <template <typename, typename> class T>
void test(T<int, std::allocator<int> /* clangd bug */> &container) {
  int result = easyfind(container, 42);
  std::cout << result << std::endl;
  try {
    easyfind(container, 0);
  } catch (const std::exception &e) {
    std::cout << "failed" << std::endl;
  }
}

template <template <typename, typename> class T> void test() {
  T<int, std::allocator<int> /* clangd bug */> container;
  container.push_back(42);
  test(container);
}

int main(void) {
  test<std::vector>();
  test<std::deque>();
  test<std::list>();
}
