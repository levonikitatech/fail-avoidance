#if !defined(ATTEMPT_HPP)
#define ATTEMPT_HPP
#include <memory>
#include <stdint.h>
#include <string>

#include "Answer.hpp"
#include "Person.hpp"
#include "Question.hpp"

using namespace std;

class Attempt
{
private:
    /* data */
    auto_ptr<Person> person;
    uint8_t currentQuestion;
    vector<Answer> answers;
public:
    Attempt();
    ~Attempt();
    Question* NextQuestion(); // TODO: alexEP
    void GiveAnswer(Answer answer); // TODO: alexEP 
};

#endif // ATTEMPT_HPP
