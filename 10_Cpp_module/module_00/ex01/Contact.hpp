#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

    private:
        int index;
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string secret;

    public:
        Contact();
        Contact(int index, std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret);
        void display();
        void displayDetail();
};

#endif