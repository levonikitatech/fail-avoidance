#if !defined(PERSON_HPP)
#define PERSON_HPP
#include <iostream>
#include <stdint.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Person
{
    string lastName = "";
    string name = "";
    string email = "";
    int64_t birthDate;
    int64_t testDate;
    uint8_t testResult;
    Person(char* name, char* lastName, char* email, int64_t birthDate, int64_t testDate){
        if (lastName != nullptr)
            this->lastName = string(lastName);
        if (name != nullptr)
            this->name = string(name);
        if (email != nullptr)
            this->email = string(email);
        this->birthDate = birthDate;
        this->testDate = testDate;
        this->testResult = 0; 
    };

    Person(const Person& person){
        this->lastName = person.lastName;
        this->name = person.name;
        this->email = person.email;
        this->birthDate = person.birthDate;
        this->testDate = person.testDate;
        this->testResult = person.testResult;  
    };

    static Person to_object(std::vector<std::string> record) {
        Person person(nullptr,nullptr,nullptr, 0,0);
        person.testResult = std::stoi(record.back());
        record.pop_back(); 
        person.testDate = std::stoul(record.back());
        record.pop_back();
        person.birthDate = std::stoul(record.back());
        record.pop_back();
        person.email = record.back();
        record.pop_back();
        person.name = record.back();
        record.pop_back();
        person.lastName = record.back();
        record.pop_back();
        return person;
    }

    std::stringstream to_record(std::string delimiter) {
        std::stringstream record;
        record << this->lastName << delimiter 
               << this->name << delimiter
               << this->email << delimiter
               << this->birthDate << delimiter 
               << this->testDate << delimiter
               << (uint64_t)this->testResult;
        return record; 
    };
};

#endif // PERSON_HPP
