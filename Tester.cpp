#include "Tester.hpp"

Tester::Tester(){

}

Tester::~Tester(){

}

Attempt* Tester::AddAttempt(){
    if (this->currentAttempt != nullptr) delete this->currentAttempt;
    this->currentAttempt = new Attempt();
    return this->currentAttempt;
}

Attempt* Tester::GetAttempt(){
    return this->currentAttempt;
}

static const string& Tester::GetInstruction(){
    return this->instruction;
}

void Tester::SaveCurrentAttempt(){

}

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