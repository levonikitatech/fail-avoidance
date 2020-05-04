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
};

#endif // PERSON_HPP
