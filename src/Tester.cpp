#include "Tester.hpp"

static const string Tester::INSTRUCTION = "Some instruction";

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

