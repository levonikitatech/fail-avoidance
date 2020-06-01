#include "Tester.hpp"

const string Tester::INSTRUCTION = "Вам предлагается список слов из 30 строк,\nпо 3 слова в каждой строке.\nВ каждой строке выберите только одно из трех слов,\nкоторое наиболее точно Вас характеризует,\nи пометьте его.";
const string Tester::RESULT1 = "Низкий уровень мотивация к защите.";
const string Tester::RESULT2 = "Средний уровень мотивации к защите.";
const string Tester::RESULT3 = "Высокий уровень мотивации к защите.";
const string Tester::RESULT4 = "Слишком высокий уровень мотивации к избеганию неудач, защите.";


Tester::Tester(){
    storage = std::make_unique<CSVStorage<Person>>(CSVStorage<Person>("data.csv"));
}

Tester::~Tester(){
    if (this->currentAttempt != nullptr) delete this->currentAttempt;
    this->currentAttempt = nullptr;
}

Attempt* Tester::AddAttempt(const Person& person){
    if (this->currentAttempt != nullptr) delete this->currentAttempt;
    this->currentAttempt = new Attempt(person);
    return this->currentAttempt;
}

Attempt* Tester::GetAttempt(){
    return this->currentAttempt;
}

const string& Tester::DecodeResult(uint8_t result){
    if (result < 11) 
        return RESULT1;
    if (result < 17)
        return RESULT2;
    if (result < 21)
        return RESULT3;
    return RESULT4;
}

const string& Tester::GetInstruction(){
    return INSTRUCTION;
}

void Tester::SaveCurrentAttempt(){
    this->currentAttempt->GetResult();
    this->storage->Append(this->currentAttempt->GetPerson());
    this->storage->Save();
}