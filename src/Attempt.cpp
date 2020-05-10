#include "Attempt.hpp"

Attempt::Attempt(){

}

Attempt::~Attempt(){

}

Question* Attempt::NextQuestion(){
    Question* question = new Question();
    question->first = "first";
    question->second = "second";
    question->third = "third";
    question->number = 30;
    return question;
}

void Attempt::GiveAnswer(uint8_t answer){
    
}