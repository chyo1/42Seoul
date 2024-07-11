#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
    private:
        std::string ideas[100];
        int idx;

    public:
        Brain();
        ~Brain();
        Brain(const Brain &brain);
        Brain &operator=(const Brain &brain);
        void setIdea(std::string idea);
        void getIdeas() const;
};


#endif