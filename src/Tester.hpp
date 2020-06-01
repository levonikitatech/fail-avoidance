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
    static const string RESULT1;
    static const string RESULT2;
    static const string RESULT3;
    static const string RESULT4;
    
    std::unique_ptr<CSVStorage<Person>> storage;
    Attempt* currentAttempt = nullptr; 
    
public:
    Tester(/* args */);
    ~Tester();
    Attempt* AddAttempt(const Person& person);
    Attempt* GetAttempt();
    static const string& GetInstruction();
    static const string& DecodeResult(uint8_t result);
    void SaveCurrentAttempt();
};

#endif
