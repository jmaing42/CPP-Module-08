#ifndef EX01_MUTANT_STACK_TPP_INCLUDED
#define EX01_MUTANT_STACK_TPP_INCLUDED

#include <deque>
#include <stack>

template <typename TData,
          typename TContainer = std::deque<TData> /* clangd bug */>
class MutantStack : public std::stack<TData, TContainer> {
public:
  typedef typename TContainer::iterator iterator;
  typedef typename TContainer::reverse_iterator reverse_iterator;
  typedef typename TContainer::const_iterator const_iterator;
  typedef typename TContainer::const_reverse_iterator const_reverse_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  reverse_iterator rbegin() { return this->c.rbegin(); }
  reverse_iterator rend() { return this->c.rend(); }
  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }
  const_reverse_iterator rbegin() const { return this->c.rbegin(); }
  const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
