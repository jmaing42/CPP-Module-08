#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

#include "MutantStack.tpp"

static void test() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

template <template <typename TData, typename TAllocator =
                                        std::allocator<TData> /* clangd bug */>
          class T>
static void test() {
  MutantStack<int, T<int> /* clangd bug */> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  typename MutantStack<int, T<int> /* clangd bug */>::iterator it =
      mstack.begin();
  typename MutantStack<int, T<int> /* clangd bug */>::iterator ite =
      mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int, T<int> /* clangd bug */> s(mstack);
}

int main() {
  test();
  test<std::vector>();
  test<std::deque>();
  test<std::list>();
}
