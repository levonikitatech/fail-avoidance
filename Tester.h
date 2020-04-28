#ifndef TESTER_H
#define TESTER_H
#ifdef __cplusplus
#include "Tester.hpp"
#define EXPORTCALL __attribute__((stdcall))
typedef Tester *TesterHandle;
typedef Attempt *AttemptHandle
#else
typedef struct Tester *TesterHandle;
#define EXPORTCALL
#endif

#ifdef __cplusplus
extern "C"
{
#endif
    extern TesterHandle EXPORTCALL NewTester();
    extern void EXPORTCALL DeleteTester(TesterHandle);
    extern AttemptHandle EXPORTCALL TesterAddAttempt(TesterHandle);
    extern const char* EXPORTCALL TesterGetInstruction(TesterHandle);
#ifdef __cplusplus
}
#endif

//