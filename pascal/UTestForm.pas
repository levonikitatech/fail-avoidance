unit UTestForm;

interface
uses
  Classes, 
  SysUtils, 
  Forms, 
  Controls, 
  Graphics, 
  Dialogs, 
  StdCtrls,
  MyApplicationContext,
  UTester; 

type
  TTestForm = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    procedure OnShowHandler(Sender: TObject);
  private
    FContext: PApplicationContext;
    procedure ShowQuestion();

  public
    constructor CreateNew(AOwner: TComponent; Num: Integer); override;
    procedure Init(context: PApplicationContext);

  end;

var TestForm: TTestForm;

implementation
constructor TTestForm.CreateNew(AOwner: TComponent; Num: Integer);
begin
  inherited CreateNew(AOwner, Num);
  Left := 200;
  Height := 260;
  Top := 200;
  Width := 340;
  Caption := 'Тестирование';
  ClientHeight := 260;
  ClientWidth := 340;
  LCLVersion := '2.0.8.0';
  OnShow := @OnShowHandler;
end;

procedure TTestForm.Init(context: PApplicationContext); 
begin
  FContext := context;
  Button1 := TButton.Create(TestForm);
  with Button1 do
  begin
    Left := 20;
    Height := 40;
    Top := 20;
    Width := 300;
    Caption := '';
    Font.Size := 11;
    Parent := TestForm;
  end;
  Button2 := TButton.Create(TestForm);
  with Button2 do
  begin
    Left := 20;
    Height := 40;
    Top := 70;
    Width := 300;
    Caption := '';
    Font.Size := 11;
    Parent := TestForm;
  end;
  Button3 := TButton.Create(TestForm);
  with Button3 do
  begin
    Left := 20;
    Height := 40;
    Top := 120;
    Width := 300;
    Caption := '';
    Font.Size := 11;
    Parent := TestForm;
  end;
end;

procedure TTestForm.ShowQuestion();
var 
  question: TQuestion;
begin
  question := FContext^.Tester.Attempt.NextQuestion();
  Button1.Caption := question.GetAnswerString(1);
  Button2.Caption := question.GetAnswerString(2);
  Button3.Caption := question.GetAnswerString(3);
end;

procedure TTestForm.OnShowHandler(Sender: TObject);
begin
    ShowQuestion();
end;
end.