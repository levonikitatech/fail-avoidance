#include "Attempt.hpp"
#include "Questions.hpp"

Attempt::Attempt(){
    currentQuestion = 0;
}

Attempt::~Attempt(){

}

Question* Attempt::NextQuestion(){
    Question* question = new Question();
    question->first = questions.at(currentQuestion).first;
    question->second = questions.at(currentQuestion).second;
    question->third = questions.at(currentQuestion).third;
    question->number = questions.at(currentQuestion).number;
    currentQuestion++;
    return question;
}

void Attempt::GiveAnswer(uint8_t answer){

}
