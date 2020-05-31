#if !defined(ATTEMPT_HPP)
#define ATTEMPT_HPP
#include <memory>
#include <stdint.h>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

#include "Answer.hpp"
#include "Person.hpp"
#include "Question.hpp"

class Attempt
{
private:
    void shuffleQuestion(Question *question);
    std::unique_ptr<Person> person;
    std::random_device rd;
    std::mt19937 rng;
    uint8_t currentQuestionNumber;
    Question* currentQuestion = nullptr;
    std::vector<Answer> answers; 
public:
    Attempt();
    ~Attempt();
    Question* NextQuestion(); // TODO: alexEP
    void GiveAnswer(Answer answer); // TODO: alexEP
    std::unique_ptr<Person> GetPerson();
};

#endif // ATTEMPT_HPP
