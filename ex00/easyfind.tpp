#ifndef EX00_EASYFIND_TPP_INCLUDED
#define EX00_EASYFIND_TPP_INCLUDED

#include <exception>

template <typename TContainer, typename TData>
TData easyfind(TContainer container, TData i) {
  for (typename TContainer::iterator it = container.begin();
       it != container.end(); it++) {
    if (*it == i)
      return *it;
  }
  throw std::exception();
}

template <typename T> int easyfind(T container, int i) {
  return easyfind<T, int>(container, i);
}

#endif