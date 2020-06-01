unit ULoginForm;

{$mode objfpc}{$H+}

interface

uses
  Classes, 
  SysUtils, 
  Forms, 
  Controls, 
  Graphics, 
  Dialogs, 
  StdCtrls, 
  DateTimePicker,
  Math, 
  UTester,
  dateutils, 
  UInstructionForm,
  UTestForm,
  UInfoForm,
  MyApplicationContext;


type
  TLoginForm = class(TForm)
    InstructionLabel: TLabel;
    LastNameLabel: TLabel;
    FirstNameLabel: TLabel;
    EmailLabel: TLabel;
    BirthDateLabel: TLabel;
    TestDateLabel: TLabel;
    LastNameEdit: TEdit;
    FirstNameEdit: TEdit;
    EmailEdit: TEdit;
    BirthDTP: TDateTimePicker;
    TestDTP: TDateTimePicker;
    ContinueButton: TButton;
    procedure OnContinueButtonClick(Sender: TObject);
    procedure OnShowHandler(Sender: TObject);
  private
    NullDate: TDate;
    FContext: PApplicationContext;
    
  public
    constructor Create(AOwner: TComponent); override;
  end;
var
  LoginForm: TLoginForm;
  FContext: PApplicationContext;

implementation

{$R *.lfm}

constructor TLoginForm.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  NullDate := SysUtils.MaxDateTime + 1;
  FContext := New(PApplicationContext);
  FContext^.Tester := TTester.Create();
  FContext^.LoginForm := LoginForm;
  UInstructionForm.InstructionForm := TInstructionForm.CreateNew(Application, 1);
  UTestForm.TestForm := TTestForm.CreateNew(Application, 2);
  UInfoForm.InfoForm := TInfoForm.CreateNew(Application, 3);
  FContext^.InstructionForm := UInstructionForm.InstructionForm;
  UInstructionForm.InstructionForm.Init(FContext);
  FContext^.TestForm := UTestForm.TestForm;
  UTestForm.TestForm.Init(FContext);
  FContext^.InfoForm := UInfoForm.InfoForm;
  UInfoForm.InfoForm.Init(FContext);
end;

procedure TLoginForm.OnContinueButtonClick(Sender: TObject);
var 
  person: TPerson;
begin
  person := TPerson.Create();
  person.Name := FirstNameEdit.Text;
  person.LastName := LastNameEdit.Text;
  person.Email := EmailEdit.Text;
  person.BirthDate := BirthDTP.Date;
  person.TestDate := TestDTP.Date;
  FContext^.Person := person;
  FContext^.InstructionForm.Show;
  Hide;
end;

procedure TLoginForm.OnShowHandler(Sender: TObject);
var 
  person: TPerson;
begin
  FirstNameEdit.Text := ''; 
  LastNameEdit.Text := '';
  EmailEdit.Text := '';
  BirthDTP.Date := NullDate;
  TestDTP.Date := Now();
end;
end.

