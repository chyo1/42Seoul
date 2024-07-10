#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = brain.ideas[i];
    }
    return *this;
}

Brain::Brain(const Brain &brain) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = brain.ideas[i];
    }
}