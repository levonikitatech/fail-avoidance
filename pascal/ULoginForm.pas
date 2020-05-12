unit ULoginForm;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, DateTimePicker, Math;

type
  TLoginForm = class(TForm)
    LastNameLabel: TLabel;
    FirstNameLabel: TLabel;
    EmailLabel: TLabel;
    BirthDateLabel: TLabel;
    TestDateLabel: TLabel;
    LastNameEdit: TEdit;
    FirstNameEdit: TEdit;
    EmailEdit: TEdit;    EmailEdit1: TEdit;
    BirthDTP: TDateTimePicker;
    TestDTP: TDateTimePicker;
  private
    NullDate: TDate;
  public
    constructor Create(AOwner: TComponent); override;
  end;

var
  LoginForm: TLoginForm;

implementation

{$R *.lfm}

constructor TLoginForm.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);

  NullDate := SysUtils.MaxDateTime + 1;
  BirthDTP.Date := NullDate;
  TestDTP.Date := NullDate;
end;
end.

