#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {

    public:
        MutantStack() {}

        MutantStack(const MutantStack<T>& obj) : std::stack<T>(obj) {}

        MutantStack<T>& operator=(const MutantStack<T>& obj) {
            if (this != &obj) 
                std::stack<T>::operator=(obj);
            return *this;
        }

        ~MutantStack() {}

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        // typedef typename iterator = typename std::deque<T>::iterator;
        // typedef typename const_iterator = typename std::deque<T>::const_iterator;
        // typedef typename reverse_iterator = typename std::deque<T>::reverse_iterator;
        // typedef typename const_reverse_iterator = typename std::deque<T>::const_reverse_iterator;

        iterator begin() {
            return this->c.begin();
        }

        const_iterator begin() const {
            return this->c.begin();
        }

        iterator end() {
            return this->c.end();
        }

        const_iterator end() const {
            return this->c.end();
        }


        /*---- reverse funcs ----*/
        reverse_iterator rbegin() {
            return this->c.rbegin();
        }

        const_reverse_iterator rbegin() const {
            return this->c.rbegin();
        }

        reverse_iterator rend() {
            return this->c.rend();
        }

        const_reverse_iterator rend() const {
            return this->c.rend();
        }
};

#endif