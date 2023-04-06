#ifndef EX01_MUTANT_STACK_TPP_INCLUDED
#define EX01_MUTANT_STACK_TPP_INCLUDED

#include <deque>
#include <stack>

template <typename TData,
          typename TContainer = std::deque<TData> /* clangd bug */>
class MutantStack : public std::stack<TData, TContainer> {
public:
  typedef typename TContainer::iterator iterator;

  typename TContainer::iterator begin() { return this->c.begin(); }
  typename TContainer::iterator end() { return this->c.end(); }
  typename TContainer::reverse_iterator rbegin() { return this->c.rbegin(); }
  typename TContainer::reverse_iterator rend() { return this->c.rend(); }
};

#endif
