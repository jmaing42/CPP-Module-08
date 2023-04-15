#ifndef EX00_EASYFIND_TPP_INCLUDED
#define EX00_EASYFIND_TPP_INCLUDED

#include <algorithm>
#include <exception>

template <typename T> typename T::iterator easyfind(T &container, int i) {
  const typename T::iterator result =
      std::find(container.begin(), container.end(), i);
  if (result == container.end())
    throw std::exception();
  return result;
}

#endif
