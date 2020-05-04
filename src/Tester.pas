unit Tester;

interface 

uses strings, SysUtils;

type
    testerHandle = type Pointer;
    attemptHandle = type Pointer;
    questionHandle = type Pointer;
    Tester = class
    private
        cMe: testerHandle;
        attempt: Attempt;
    public
        constructor Create();
        destructor Destroy(); override;
        function AddAttempt(): Attempt;
        function GetAttempt(): Attempt;
        function GetInstruction(): string;
    end;
    Attempt = class
    private
        cMe: attemptHandle;
    public
        constructor Create(me: attemptHandle);
        destructor Destroy(); override;
        function NextQuestion(): Question;
        procedure GiveAnswer(answer: UInt8);
    end;
function cNewTester:testerHandle; cdecl;
function cDeleteTester(handle :testerHandle); cdecl;
function cTesterAddAttempt(handle: testerHandle): attemptHandle; cdecl;
function cTesterGetAttempt(handle: testerHandle): attemptHandle; cdecl;
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
function cTesterAddAttempt(handle: testerHandle): attemptHandle; cdecl; external;
function cTesterGetAttempt(handle: testerHandle): attemptHandle; cdecl; external;
function cTesterGetInstruction(handle: testerHandle): PChar; cdecl; external;
function cAttemptNextQuestion(handle: attemptHandle): questionHandle; cdecl; external;
function cAttemptGiveAnswer(handle: attemptHandle; answer: UInt8); cdecl; external;
function cQuestionGetAnswerString(handle: questionHandle; answer: UInt8): PChar; cdecl; external;
function cQuestionGetNumber(handle: questionHandle): UInt8; cdecl; external;

constructor Tester.Create();
begin
  cMe := cNewTester();
end;

destructor Tester.Destroy();
begin
  cDeleteTester(cMe);
end;

function Tester.AddAttempt(): Attempt;
begin
  attempt := Attempt.Create(cTesterAddAttemt(cMe));
  Result := attempt;
end;

function Tester.GetAttempt(): Attempt;
begin
  Result := attempt;
end;

function Tester.GetInstruction(): String;
begin
  Result := StrPas(cTesterGetInstruction(cMe));
end;

constructor Attempt.Create(me: attemptHandle);
begin
  cMe := me;
end;

destructor Attempt.Destroy();
begin
  Dispose(cMe);
end; 

function Attempt.NextQuestion(): Question;
begin
  
end;

procedure Attempt.GiveAnswer(answer: UInt8);
begin
  cAttemptGiveAnswer(cMe, answer);
end;
end.