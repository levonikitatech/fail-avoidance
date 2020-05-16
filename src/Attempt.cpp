#include "Attempt.hpp"
#include "Questions.hpp"

Attempt::Attempt(){
    currentQuestion = 0;
    std::mt19937 rng(rd());
}

Attempt::~Attempt(){

}

Question* Attempt::NextQuestion(){
    Question* question = new Question();
    question->first = questions.at(currentQuestion).first;
    question->second = questions.at(currentQuestion).second;
    question->third = questions.at(currentQuestion).third;
    question->number = questions.at(currentQuestion).number;
    shuffleQuestion(question);
    currentQuestion++;
    return question;
}

void Attempt::GiveAnswer(uint8_t answer){

}

void Attempt::shuffleQuestion(Question *question){
    std::vector<std::string> temp {question->first, question->second, question->third};
    std::shuffle(temp.begin(), temp.end(), this->rng);
    question->first = temp.at(0);
    question->second = temp.at(1);
    question->third = temp.at(2);
}
