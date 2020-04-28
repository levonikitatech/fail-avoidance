#ifndef TESTER_H
#define TESTER_H
#ifdef __cplusplus
#include "Tester.hpp"
#define EXPORTCALL __attribute__((stdcall))
typedef Tester *TesterHandle;
typedef Attempt *AttemptHandle;
typedef Question *QuestionHandle;
#else
typedef struct Tester *TesterHandle;
typedef struct Attempt *AttemptHandle;
typedef struct Question *QuestionHandle;
#define EXPORTCALL
#endif

#ifdef __cplusplus
extern "C"
{
#endif
    extern TesterHandle EXPORTCALL NewTester();
    extern void EXPORTCALL DeleteTester(TesterHandle);
    extern AttemptHandle EXPORTCALL TesterAddAttempt(TesterHandle);
    extern AttemptHandle EXPORTCALL TesterGetAttempt(TesterHandle);
    extern const char* EXPORTCALL TesterGetInstruction(TesterHandle);
    extern void EXPORTCALL TesterSaveCurrentAttempt(TesterHandle);
    extern QuestionHandle EXPORTCALL AttemptNextQuestion(AttemptHandle);
    extern const char* EXPORTCALL QuestionGetAnswerString(QuestionHandle, uint8_t);
    extern uint8_t EXPORTCALL QuestionGetNumber(QuestionHandle); 
#ifdef __cplusplus
}
#endif

//