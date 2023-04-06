#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

#include "easyfind.tpp"

template <template <typename TData, typename TAllocator =
                                        std::allocator<TData> /* clangd bug */>
          class T>
void test(T<int> &container, int value) {
  try {
    for (typename T<int>::iterator iter = easyfind(container, value);
         iter != container.end(); iter++) {
      std::cout << *iter << std::endl;
    }
  } catch (const std::exception &e) {
    std::cout << "failed" << std::endl;
  }
}

template <template <typename TData, typename TAllocator =
                                        std::allocator<TData> /* clangd bug */>
          class T>
void test() {
  T<int> container;
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
