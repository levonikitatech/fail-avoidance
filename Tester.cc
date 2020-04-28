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
}