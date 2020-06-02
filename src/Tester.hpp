#ifndef TESTER_HPP
#define TESTER_HPP
#include <memory>
#include <vector>
#include <stdint.h>
#include <string>

#include "Attempt.hpp"
#include "CSVAdapter.hpp"

class Tester
{
private:
    /* data */
    static const std::string INSTRUCTION;
    static const std::string RESULT1;
    static const std::string RESULT2;
    static const std::string RESULT3;
    static const std::string RESULT4;

    std::unique_ptr<CSVStorage<Person>> storage;
    Attempt* currentAttempt = nullptr;

public:
    Tester(/* args */);
    ~Tester();
    Attempt* AddAttempt(const Person& person);
    Attempt* GetAttempt();
    static const std::string& GetInstruction();
    static const std::string& DecodeResult(uint8_t result);
    void SaveCurrentAttempt();
};

#endif
