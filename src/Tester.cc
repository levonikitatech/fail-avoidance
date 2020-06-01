#include "Tester.h"
extern "C"  {
    TesterHandle EXPORTCALL NewTester(){
        return new Tester;
    };
    void EXPORTCALL DeleteTester(TesterHandle handle){
        delete handle;
    };
    AttemptHandle EXPORTCALL TesterAddAttempt(TesterHandle handle, PersonHandle person){
        return handle->AddAttempt(*person);
    };
    AttemptHandle EXPORTCALL TesterGetAttempt(TesterHandle handle){
        return handle->GetAttempt();
    };
    const char* EXPORTCALL TesterGetInstruction(TesterHandle handle){
        return handle->GetInstruction().c_str();
    };
    const char* EXPORTCALL TesterDecodeResult(TesterHandle handle, uint8_t result){
        return handle->DecodeResult(result).c_str();
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
    uint8_t EXPORTCALL AttemptGetResult(AttemptHandle handle){
        return handle->GetResult();
    }
    const char* EXPORTCALL QuestionGetAnswerString(QuestionHandle handle, uint8_t answer){
        if (answer == 1) return handle->first.answer.c_str();
        if (answer == 2) return handle->second.answer.c_str();
        return handle->third.answer.c_str();
    };
    uint8_t EXPORTCALL QuestionGetNumber(QuestionHandle handle){
        return handle->number;
    }
    bool EXPORTCALL IsEmailValid(){
        return 1;
    }

    PersonHandle EXPORTCALL NewPerson(char* name, char* lastName, char* email, int64_t birthDate, int64_t testDate){
        return new Person(name, lastName, email, birthDate, testDate);
    }
}