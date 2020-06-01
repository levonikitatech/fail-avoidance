unit UInstructionForm;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, UTester,dateutils, MyApplicationContext;

type 
  TInstructionForm = class(TForm)
    InstructionLabel: TLabel;
    ContinueButton: TButton;
    procedure OnContinueButtonClick(Sender: TObject);
    procedure OnCloseHandler(Sender: TObject; var CloseAction: TCloseAction);
  private
    FContext: PApplicationContext;

  public
    constructor CreateNew(AOwner: TComponent; Num: Integer); override;
    procedure Init(context: PApplicationContext);
  end;

var InstructionForm: TInstructionForm;

implementation 

constructor TInstructionForm.CreateNew(AOwner: TComponent; Num: Integer);
begin
  inherited CreateNew(AOwner, Num);
  Left := 200;
  Height := 260;
  Top := 200;
  Width := 500;
  Caption := 'Инструкция';
  ClientHeight := 260;
  ClientWidth := 500;
  LCLVersion := '2.0.8.0';
  OnClose := @OnCloseHandler;
end;

procedure TInstructionForm.Init(context: PApplicationContext);
begin
  FContext := context;
  InstructionLabel := TLabel.Create(InstructionForm);
  with InstructionLabel do
  begin    
    Left := 0;
    Height := 200;
    Top := 0;
    Width := 500;
    Caption := FContext^.Tester.GetInstruction();
    ParentColor := False;
    Alignment := taCenter;
    Layout := tlCenter;
    OptimalFill := True;
    Font.Size := 11;
    Parent := InstructionForm;
  end;
  ContinueButton := TButton.Create(InstructionForm);
  with ContinueButton do
  begin
    Left := 105;
    Height := 40;
    Top := 200;
    Width := 290;
    Caption := 'Приступить к тесту>';
    Font.Size := 12;
    Parent := InstructionForm;
    OnClick := @OnContinueButtonClick;
  end
end;

procedure TInstructionForm.OnContinueButtonClick(Sender: TObject);
begin
  FContext^.Tester.AddAttempt(FContext^.Person);
  FContext^.TestForm.Show;
  Hide;
end;

procedure TInstructionForm.OnCloseHandler(Sender: TObject; var CloseAction: TCloseAction);
begin
  FContext^.LoginForm.Show;
end;
end.