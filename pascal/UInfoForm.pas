  unit UInfoForm;

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
  TInfoForm = class(TForm)
    ResultLabel: TLabel;
    OKButton: TButton; 
    procedure OnShowHandler(Sender: TObject);
    procedure OnClickHandler(Sender: TObject);
    procedure OnCloseHandler(Sender: TObject; var CloseAction: TCloseAction);
  private
    FContext: PApplicationContext;
  public
    constructor CreateNew(AOwner: TComponent; Num: Integer); override;
    procedure Init(context: PApplicationContext);

  end;

var InfoForm: TInfoForm;

implementation
constructor TInfoForm.CreateNew(AOwner: TComponent; Num: Integer);
begin
  inherited CreateNew(AOwner, Num);
  Left := 200;
  Height := 260;
  Top := 200;
  Width := 500;
  Caption := 'Результат';
  ClientHeight := 260;
  ClientWidth := 500;
  LCLVersion := '2.0.8.0';
  OnShow := @OnShowHandler;
end;

procedure TInfoForm.Init(context: PApplicationContext); 
begin
  FContext := context;
  ResultLabel := TLabel.Create(InfoForm);
  with ResultLabel do
  begin    
    Left := 0;
    Height := 200;
    Top := 0;
    Width := 500;
    Caption := '';
    ParentColor := False;
    Alignment := taCenter;
    Layout := tlCenter;
    OptimalFill := True;
    Font.Size := 11;
    Parent := InfoForm;
  end;
  OKButton := TButton.Create(InfoForm);
  with OKButton do
  begin
    Left := 105;
    Height := 40;
    Top := 200;
    Width := 290;
    Caption := 'OK';
    Font.Size := 12;
    Parent := InfoForm;
    OnClick := @OnClickHandler;
  end  
end;

procedure TInfoForm.OnShowHandler(Sender: TObject);
begin
    ResultLabel.Caption := FContext^.Tester.DecodeResult(FContext^.Tester.Attempt.GetResult());
end;

procedure TInfoForm.OnClickHandler(Sender: TObject);
begin
    FContext^.LoginForm.Show;
    Hide;
end;

procedure TInfoForm.OnCloseHandler(Sender: TObject; var CloseAction: TCloseAction);
begin
  FContext^.LoginForm.Show;
end;
end.