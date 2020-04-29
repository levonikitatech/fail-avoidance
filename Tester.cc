#include "Tester.h"
extern "C"  {
    TesterHandle EXPORTCALL NewTester(){
        return new Tester;
    };
    void EXPORTCALL DeleteTester(TesterHandle handle){
        delete handle;
    };
    AttemptHandle EXPORTCALL TesterAddAttempt(TesterHandle handle){
        return handle->AddAttempt();
    };
    AttemptHandle EXPORTCALL TesterGetAttempt(TesterHandle handle){
        return handle->GetAttempt();
    };
    const char* EXPORTCALL TesterGetInstruction(TesterHandle handle){
        return handle->GetInstruction().c_str();
    };
    void EXPORTCALL TesterSaveCurrentAttempt(TesterHandle handle){
        handle->SaveCurrentAttempt();
    };
    QuestionHandle EXPORTCALL AttemptNextQuestion(AttemptHandle handle){
        return handle->NextQuestion();
    };
    void EXPORTCALL AttemptGiveAnswer(AttemptHandle handle, uint8_t answer){
        handle->GiveAnswer(answer);
    }
    const char* EXPORTCALL QuestionGetAnswerString(QuestionHandle handle, uint8_t answer){
        if (answer == 1) return handle->first.c_str();
        if (answer == 2) return handle->second.c_str();
        return handle->third.c_str();
    };
    uint8_t EXPORTCALL QuestionGetNumber(QuestionHandle handle){
        return handle->number;
    }
}