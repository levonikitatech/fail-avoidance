#if !defined(ATTEMPT_HPP)
#define ATTEMPT_HPP
#include <memory>
#include <stdint.h>
#include <string>
#include <vector>

#include "Answer.hpp"
#include "Person.hpp"
#include "Question.hpp"

class Attempt
{
private:
    /* data */
    std::auto_ptr<Person> person;
    uint8_t currentQuestion;
    std::vector<Answer> answers;
public:
    Attempt();
    ~Attempt();
    Question* NextQuestion(); // TODO: alexEP
    void GiveAnswer(Answer answer); // TODO: alexEP 
};

#endif // ATTEMPT_HPP
