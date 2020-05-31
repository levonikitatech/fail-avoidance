#ifndef TESTER_HPP
#define TESTER_HPP
#include <memory>
#include <vector>
#include <stdint.h>
#include <string>

#include "Attempt.hpp"
#include "CSVAdapter.hpp"

using namespace std;

class Tester
{
private:
    /* data */
    static const string INSTRUCTION; 
    std::unique_ptr<CSVStorage<Person>> storage;
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
