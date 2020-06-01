 #include "Attempt.hpp"
#include "Questions.hpp"

Attempt::Attempt(const Person& person1){
    currentQuestionNumber = 0;
    std::mt19937 rng(rd());
    person = std::make_unique<Person>(person1);
}

Attempt::~Attempt(){ 
}

Question* Attempt::NextQuestion(){
    if (this->currentQuestion != nullptr) delete this->currentQuestion;
    this->currentQuestion = new Question();
    this->currentQuestion->first = questions.at(currentQuestionNumber).first;
    this->currentQuestion->second = questions.at(currentQuestionNumber).second;
    this->currentQuestion->third = questions.at(currentQuestionNumber).third;
    this->currentQuestion->number = questions.at(currentQuestionNumber).number;
    shuffleQuestion(this->currentQuestion);
    currentQuestionNumber++;
    return this->currentQuestion;
}

void Attempt::GiveAnswer(uint8_t answer){
    if (answer == 0)
        this->answers.push_back(
            this->currentQuestion->first.number
        );
    else if (answer == 1)
        this->answers.push_back(
            this->currentQuestion->second.number 
        );
    else
        this->answers.push_back(
            this->currentQuestion->third.number 
        );
}

void Attempt::shuffleQuestion(Question *question){
    std::vector<QuestionString> temp {question->first, question->second, question->third};
    std::shuffle(temp.begin(), temp.end(), this->rng);
    question->first = temp.at(0);
    question->second = temp.at(1);
    question->third = temp.at(2);
}

uint8_t Attempt::GetResult(){
    uint8_t result = 0;
    if (this->answers[0] == 1) result++;
    if (this->answers[1] == 0 || this->answers[1] == 1) result++;
    if (this->answers[2] == 0 || this->answers[2] == 2) result++;
    if (this->answers[3] == 2) result++;
    if (this->answers[4] == 1) result++;
    if (this->answers[5] == 2) result++;
    if (this->answers[6] == 1 || this->answers[6] == 2) result++;
    if (this->answers[7] == 2) result++;
    if (this->answers[8] == 0 || this->answers[8] == 2) result++;
    if (this->answers[9] == 1) result++;
    if (this->answers[10] == 0 || this->answers[10] == 1) result++;
    if (this->answers[11] == 0 || this->answers[11] == 2) result++;
    if (this->answers[12] == 1 || this->answers[12] == 2) result++;
    if (this->answers[13] == 0) result++;
    if (this->answers[14] == 0) result++;
    if (this->answers[15] == 1 || this->answers[15] == 2) result++;
    if (this->answers[16] == 2) result++;
    if (this->answers[17] == 0) result++;
    if (this->answers[18] == 1) result++;
    if (this->answers[19] == 0 || this->answers[19] == 1) result++;
    if (this->answers[20] == 0) result++;
    if (this->answers[21] == 0) result++;
    if (this->answers[22] == 2) result++;
    if (this->answers[23] == 0 || this->answers[23] == 1) result++;
    if (this->answers[24] == 0) result++;
    if (this->answers[25] == 1) result++;
    if (this->answers[26] == 2) result++;
    if (this->answers[27] == 0 || this->answers[27] == 1) result++;
    if (this->answers[28] == 2) result++;
    if (this->answers[29] == 1) result++;
    this->person->testResult = result;
    return result;    
}

Person* Attempt::GetPerson(){
    Person* person = this->person.get();
    return person;
}
