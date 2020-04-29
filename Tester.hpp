#ifndef TESTER_HPP
#define TESTER_HPP
#include <memory>
#include <vector>
#include <stdint.h>
#include <string>

#include "Storage.hpp"

using namespace std;
typedef uint8_t Answer;

class Tester
{
private:
    /* data */
    static const string instruction = "Some instruction"; 
    std::auto_ptr<Storage> storage;
    Attempt* currentAttempt = nullptr; 
public:
    Tester(/* args */);
    ~Tester();
    Attempt* AddAttempt();
    Attempt* GetAttempt();
    static const string& GetInstruction();
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
