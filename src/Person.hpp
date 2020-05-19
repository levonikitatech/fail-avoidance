#if !defined(PERSON_HPP)
#define PERSON_HPP
#include <stdint.h>
#include <string>

using namespace std;

struct Person
{
    string lastName;
    string name;
    string email;
    int64_t birthDate;
    int64_t testDate;

    Person(char* name, char* lastName, char* email, int64_t birthDate, int64_t testDate){
        this->lastName = string(lastName);
        this->name = string(name);
        this->email = string(email);
        this->birthDate = birthDate;
        this->testDate = testDate; 
    };
};

#endif // PERSON_HPP
