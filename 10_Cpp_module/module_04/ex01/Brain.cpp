#include "Brain.hpp"
#include <iostream>

Brain::Brain() : idx(0) {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain) {
	this->idx = brain.idx;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = brain.ideas[i];
    }
    return *this;
}

Brain::Brain(const Brain &brain) : idx(brain.idx) {
    for (int i = 0; i < brain.idx; i++) {
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