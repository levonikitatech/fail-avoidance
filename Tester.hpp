#ifndef TESTER_HPP
#define TESTER_HPP
#include <memory>
#include <vector>
#include <stdint.h>
#include <string>

#include <Storage.hpp>
class Tester
{
private:
    /* data */
    std::auto_ptr<Storage> storage;
public:
    Tester(/* args */);
    ~Tester();
    Attempt* AddAttempt();
    sting GetInstruction();
    Save
};

struct Attempt
{
    /* data */
    std::auto_ptr<Person> person; 
    Question NextQuestion(); // TODO: alexEP
    uint8_t currentQuestion;
    vector<Answer> answers;
};

struct Answer
{
    uint8_t Answer;
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
    //TODO: alexEP
};




#endif