unit Tester;

interface 

uses SysUtils;

type
    testerHandle = type Pointer;
    attemptHandle = type Pointer;
    questionHandle = type Pointer;
    Tester = class
    private
        cMe: testerHandle;
    public
        constructor Create();
        destructor Destroy(); override;
        function AddAttempt(): Attempt;
        function GetAttempt(): Attempt;
        
    end;
function cNewTester:testerHandle; cdecl;
function cDeleteTester(handle :testerHandle); cdecl;
function cTesterAddAttemt(handle: testerHandle): attemptHandle; cdecl;
function cTesterGetAttemt(handle: testerHandle): attemptHandle; cdecl;
function cTesterGetInstruction(handle: testerHandle): PChar; cdecl;
function cAttemptNextQuestion(handle: attemptHandle): questionHandle; cdecl;
function cAttemptGiveAnswer(handle: attemptHandle; answer: UInt8); cdecl;
function cQuestionGetAnswerString(handle: questionHandle; answer: UInt8): PChar; cdecl;
function cQuestionGetNumber(handle: questionHandle): UInt8; cdecl;

implementation

{$link Tester_c.o}
{$linklib libtester.so}
{$linklib c}
{$linklib stdc++}

function cNewTester:testerHandle; cdecl; external;
function cDeleteTester(handle :testerHandle); cdecl; external;
function cTesterAddAttemt(handle: testerHandle): attemptHandle; cdecl; external;
function cTesterGetAttemt(handle: testerHandle): attemptHandle; cdecl; external;
function cTesterGetInstruction(handle: testerHandle): PChar; cdecl; external;
function cAttemptNextQuestion(handle: attemptHandle): questionHandle; cdecl; external;
function cAttemptGiveAnswer(handle: attemptHandle; answer: UInt8); cdecl; external;
function cQuestionGetAnswerString(handle: questionHandle; answer: UInt8): PChar; cdecl; external;
function cQuestionGetNumber(handle: questionHandle): UInt8; cdecl; external;


end.