#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    idx = 0;
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

void Brain::setIdea(std::string idea) {
    this->ideas[(idx++) % 100] = idea;
}

void Brain::getIdeas() const {
    for (int i = 0; i < idx; i++) {
        std::cout << this->ideas[i] << std::endl;
    }
}