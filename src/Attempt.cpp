#include "Attempt.hpp"
#include "Questions.hpp"

Attempt::Attempt(){
    currentQuestionNumber = 0;
    std::mt19937 rng(rd());
    std::vector<Answer> answers();
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
}

void Attempt::shuffleQuestion(Question *question){
    std::vector<QuestionString> temp {question->first, question->second, question->third};
    std::shuffle(temp.begin(), temp.end(), this->rng);
    question->first = temp.at(0);
    question->second = temp.at(1);
    question->third = temp.at(2);
}
