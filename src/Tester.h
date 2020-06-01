#ifndef TESTER_H
#define TESTER_H
#include <stdint.h>
#ifdef __cplusplus
#include "Tester.hpp"
#include "Question.hpp"
#include "Person.hpp"
#define EXPORTCALL __attribute__((stdcall))
typedef Tester *TesterHandle;
typedef Attempt *AttemptHandle;
typedef Question *QuestionHandle;
typedef Person *PersonHandle;
#else
typedef struct Tester *TesterHandle;
typedef struct Attempt *AttemptHandle;
typedef struct Question *QuestionHandle;
typedef struct Person *PersonHandle;
#define EXPORTCALL
typedef uint8_t bool;
#endif
#ifdef __cplusplus
extern "C"
{
#endif
    extern TesterHandle EXPORTCALL NewTester();
    extern void EXPORTCALL DeleteTester(TesterHandle);
    extern AttemptHandle EXPORTCALL TesterAddAttempt(TesterHandle, PersonHandle);
    extern AttemptHandle EXPORTCALL TesterGetAttempt(TesterHandle); 
    extern const char* EXPORTCALL TesterGetInstruction(TesterHandle);
    extern const char* EXPORTCALL TesterDecodeResult(TesterHandle, uint8_t);
    extern void EXPORTCALL TesterSaveCurrentAttempt(TesterHandle);
    extern QuestionHandle EXPORTCALL AttemptNextQuestion(AttemptHandle);
    extern uint8_t EXPORTCALL AttemptGetResult(AttemptHandle);
    extern void EXPORTCALL AttemptGiveAnswer(AttemptHandle, uint8_t);
    extern const char* EXPORTCALL QuestionGetAnswerString(QuestionHandle, uint8_t);
    extern uint8_t EXPORTCALL QuestionGetNumber(QuestionHandle); 
    extern bool EXPORTCALL IsEmailValid();
    extern PersonHandle EXPORTCALL NewPerson(char*, char*, char*, int64_t, int64_t);
#ifdef __cplusplus
}
#endif

#endif //TESTER_H