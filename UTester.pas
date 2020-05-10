unit UTester;

{$mode objfpc}{$H+}{$J-}
interface 

uses strings, SysUtils;

type
    testerHandle = type Pointer;
    attemptHandle = type Pointer;
    questionHandle = type Pointer;
    Question = class
    private
        cMe: questionHandle;
    public
        function GetAnswerString(answer: UInt8): String;
        function GetNumber(): UInt8;
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
    TTester = class
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

function NewTester:testerHandle; cdecl;
procedure DeleteTester(handle :testerHandle); cdecl;
function TesterAddAttempt(handle: testerHandle): attemptHandle; cdecl;
function TesterGetAttempt(handle: testerHandle): attemptHandle; cdecl;
function TesterGetInstruction(handle: testerHandle): PChar; cdecl;
function AttemptNextQuestion(handle: attemptHandle): questionHandle; cdecl;
procedure AttemptGiveAnswer(handle: attemptHandle; answer: UInt8); cdecl;
function QuestionGetAnswerString(handle: questionHandle; answer: UInt8): PChar; cdecl;
function QuestionGetNumber(handle: questionHandle): UInt8; cdecl;

implementation

{$link Attempt.o}
{$link Tester_c.o}
{$linklib libtester.so}
{$linklib c}
{$linklib stdc++}

function NewTester:testerHandle; cdecl; external;
procedure DeleteTester(handle :testerHandle); cdecl; external;
function TesterAddAttempt(handle: testerHandle): attemptHandle; cdecl; external;
function TesterGetAttempt(handle: testerHandle): attemptHandle; cdecl; external;
function TesterGetInstruction(handle: testerHandle): PChar; cdecl; external;
function AttemptNextQuestion(handle: attemptHandle): questionHandle; cdecl; external;
procedure AttemptGiveAnswer(handle: attemptHandle; answer: UInt8); cdecl; external;
function QuestionGetAnswerString(handle: questionHandle; answer: UInt8): PChar; cdecl; external;
function QuestionGetNumber(handle: questionHandle): UInt8; cdecl; external;

constructor TTester.Create();
begin
  cMe := NewTester();
end;

destructor TTester.Destroy();
begin
  DeleteTester(cMe);
end;

function TTester.AddAttempt(): Attempt;
begin
  attempt := Attempt.Create(TesterAddAttempt(cMe));
  Result := attempt;
end;

function TTester.GetAttempt(): Attempt;
begin
  Result := attempt;
end;

function TTester.GetInstruction(): String;
begin
  Result := StrPas(TesterGetInstruction(cMe));
end;

constructor Attempt.Create(me: attemptHandle);
begin
  cMe := me;
end;

destructor Attempt.Destroy();
begin
  //ispose(cMe);
end; 

function Attempt.NextQuestion(): Question;
begin
  
end;

procedure Attempt.GiveAnswer(answer: UInt8);
begin
  AttemptGiveAnswer(cMe, answer);
end;

function Question.GetAnswerString(answer: UInt8): String;
begin
  Result := StrPas(QuestionGetAnswerString(cMe, answer));
end;

function Question.GetNumber(): UInt8;
begin
  Result := QuestionGetNumber(cMe);
end;

end.
