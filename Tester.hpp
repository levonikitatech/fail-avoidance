#ifndef TESTER_HPP
#define TESTER_HPP
#include <memory>
#include <vector>
#include <stdint.h>
#include <string>

#include <Storage.hpp>

typedef Answer uint8_t;

class Tester
{
private:
    /* data */
    std::auto_ptr<Storage> storage;
    Attempt* currentAttempt; 
public:
    Tester(/* args */);
    ~Tester();
    Attempt* AddAttempt();
    Attempt* GetAttempt();
    static const sting& GetInstruction();
    void SaveCurrentAttempt();
};

class Attempt
{
private:
    /* data */
    std::auto_ptr<Person> person;
    uint8_t currentQuestion;
    vector<Answer> answers;
public:
    Attempt();
    ~Attempt();
    Question* NextQuestion(); // TODO: alexEP
    void GiveAnswer(Answer answer); // TODO: alexEP 
};


struct Question
{
    string first;
    string second;
    string third;
    uint8_t number;
};

struct Person
{
    string lastName;
    string name;
    string email;
    int64_t birthDate;
    int64_t testDate;
};




#endif
