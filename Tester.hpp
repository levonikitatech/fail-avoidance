#ifndef TESTER_HPP
#define TESTER_HPP
#include <memory>
#include <vector>
#include <stdint.h>
#include <string>

#include "Attempt.hpp"
#include "Storage.hpp"

using namespace std;

class Tester
{
private:
    /* data */
    static const string INSTRUCTION; 
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

#endif
