unit UTester;

{$mode objfpc}{$H+}{$J-}
interface 

uses strings, SysUtils, dateUtils;

type
    testerHandle = type Pointer;
    attemptHandle = type Pointer;
    questionHandle = type Pointer;
    personHandle = type Pointer;
  TPerson = class
  private
    var pName : String;
    var pLastName : String;
    var pEmail : String;
    var pValidEmail : Boolean;
    var pBirthDate : Int64;
    var pTestDate: Int64;
    function GetBirthDate: TDateTime;
    function GetTestDate:  TDateTime;
    procedure SetEmail(const Value: String);
    procedure SetBirthDate(const Value: TDateTime);
    procedure SetTestDate(const Value: TDateTime);    
  published
    property ValidEmail: Boolean read pValidEmail; 
    property Name: String  read pName write pName;
    property LastName: String read pLastName write pLastName;
    property Email: String read pEmail write SetEmail;
    property BirthDate: TDateTime read GetBirthDate write SetBirthDate;
    property TestDate: TDateTime read GetTestDate write SetTestDate;
    property BirthDateUTC: Int64 read pBirthDate;
    property TestDateUTC: Int64 read pTestDate;
  end; 
  TQuestion = class
    private
        cMe: questionHandle;
    public
        constructor Create(me: questionHandle);
        function GetAnswerString(answer: UInt8): String;
        function GetNumber(): UInt8;
    end;
    TAttempt  = class
    private
        cMe: attemptHandle;
    public
        constructor Create(me: attemptHandle);
        destructor Destroy(); override;
        function NextQuestion(): TQuestion;
        procedure GiveAnswer(answer: UInt8);
    end;
    TTester = class
    private
        cMe: testerHandle;
        FAttempt: TAttempt;
    public
        constructor Create();
        destructor Destroy(); override;
        procedure AddAttempt(person: TPerson);
        function GetInstruction(): string;
        property Attempt: TAttempt read FAttempt;
    end;

function NewTester:testerHandle; cdecl;
procedure DeleteTester(handle :testerHandle); cdecl;
function TesterAddAttempt(handle: testerHandle; person: personHandle): attemptHandle; cdecl;
function TesterGetInstruction(handle: testerHandle): PChar; cdecl;
function AttemptNextQuestion(handle: attemptHandle): questionHandle; cdecl;
procedure AttemptGiveAnswer(handle: attemptHandle; answer: UInt8); cdecl;
function QuestionGetAnswerString(handle: questionHandle; answer: UInt8): PChar; cdecl;
function QuestionGetNumber(handle: questionHandle): UInt8; cdecl;
function IsEmailValid(email: PChar): Boolean; cdecl;

implementation

{$link Attempt.o}
{$link Tester_c.o}
{$linklib libtester.so}
{$linklib c}
{$linklib stdc++}

function NewTester:testerHandle; cdecl; external;
procedure DeleteTester(handle :testerHandle); cdecl; external;
function TesterAddAttempt(handle: testerHandle; person: personHandle): attemptHandle; cdecl; external;
function TesterGetInstruction(handle: testerHandle): PChar; cdecl; external;
function AttemptNextQuestion(handle: attemptHandle): questionHandle; cdecl; external;
procedure AttemptGiveAnswer(handle: attemptHandle; answer: UInt8); cdecl; external;
function QuestionGetAnswerString(handle: questionHandle; answer: UInt8): PChar; cdecl; external;
function QuestionGetNumber(handle: questionHandle): UInt8; cdecl; external;
function IsEmailValid(email: PChar): Boolean; cdecl; external;
function NewPerson(name: PChar; LastName: PChar; email: PChar; BirthDate: Int64; TestDate: Int64): personHandle; cdecl; external;

constructor TTester.Create();
begin
  cMe := NewTester();
end;

destructor TTester.Destroy();
begin
  DeleteTester(cMe);
end;

procedure TTester.AddAttempt(person: TPerson);
var
  cPerson: personHandle;
begin
  cPerson := NewPerson(PChar(person.Name), PChar(person.LastName), PChar(person.Email), person.BirthDateUTC, person.TestDateUTC);
  FAttempt := TAttempt.Create(TesterAddAttempt(cMe, cPerson));
end;

function TTester.GetInstruction(): String;
begin
  Result := StrPas(TesterGetInstruction(cMe));
end;

constructor TAttempt.Create(me: attemptHandle);
begin
  cMe := me;
end;

destructor TAttempt.Destroy();
begin
  raise EInvalidPointer.Create('Attempt is managed by tester'); 
end; 

function TAttempt.NextQuestion(): TQuestion;
begin
  Result := TQuestion.Create(AttemptNextQuestion(cMe));  
end;

procedure TAttempt.GiveAnswer(answer: UInt8);
begin
  AttemptGiveAnswer(cMe, answer);
end;

constructor TQuestion.Create(me: questionHandle);
begin
  cMe := me;  
end;

function TQuestion.GetAnswerString(answer: UInt8): String;
begin
  Result := StrPas(QuestionGetAnswerString(cMe, answer));
end;

function TQuestion.GetNumber(): UInt8;
begin
  Result := QuestionGetNumber(cMe);
end;

procedure TPerson.SetEmail(const Value: String);
begin
  pValidEmail := IsEmailValid(PChar(Value));
  if pValidEmail then
    pEmail := Value;
end;

function TPerson.GetBirthDate: TDateTime;
begin
  Result := UnixToDateTime(pBirthDate);
end;

procedure TPerson.SetBirthDate(const Value: TDateTime);
begin
  pBirthDate := DateTimeToUnix(Value);
end;

function TPerson.GetTestDate:  TDateTime;
begin
  Result := UnixToDateTime(pTestDate);
end;

procedure TPerson.SetTestDate(const Value: TDateTime);
begin
  pTestDate := DateTimeToUnix(Value);
end;
end.
