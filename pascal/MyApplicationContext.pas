unit MyApplicationContext;

interface
 uses Classes, 
  SysUtils, 
  Forms,
  UTester;

type TApplicationContext = record
    Tester: TTester;
    LoginForm: TForm;
    InstructionForm: TForm;
    TestForm: TForm;
    Person: TPerson;
    Attempt: TAttempt;
end;

type PApplicationContext = ^TApplicationContext;

implementation
end.