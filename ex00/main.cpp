#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <queue>
#include <stack>
#include <vector>

#include "easyfind.tpp"

template <template <typename, typename> class T>
void test(T<int, std::allocator<int> /* clangd bug */> &container, int value) {
  try {
    for (typename T<int, std::allocator<int> /* clangd bug */>::iterator iter =
             easyfind(container, value);
         iter != container.end(); iter++) {
      std::cout << *iter << std::endl;
    }
  } catch (const std::exception &e) {
    std::cout << "failed" << std::endl;
  }
}

template <template <typename, typename> class T> void test() {
  T<int, std::allocator<int> /* clangd bug */> container;
  container.push_back(4);
  container.push_back(2);
  container.push_back(42);
  container.push_back(4242);
  test(container, 42);
  test(container, 0);
}

int main(void) {
  test<std::vector>();
  test<std::deque>();
  test<std::list>();
}
