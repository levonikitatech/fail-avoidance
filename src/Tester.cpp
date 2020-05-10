#include "Tester.hpp"

const string Tester::INSTRUCTION = "Вам предлагается список слов из 30 строк, по 3 слова в каждой строке. В каждой строке выберите только одно из трех слов, которое наиболее точно Вас характеризует, и пометьте его.";

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

const string& Tester::GetInstruction(){
    return INSTRUCTION;
}

void Tester::SaveCurrentAttempt(){

}
