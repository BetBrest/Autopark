object Form5: TForm5
  Left = 473
  Top = 193
  BorderStyle = bsSingle
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1084#1072#1096#1080#1085#1099
  ClientHeight = 625
  ClientWidth = 843
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 110
    Top = 98
    Width = 113
    Height = 16
    Caption = #1058#1080#1087' '#1072#1074#1090#1086#1084#1086#1073#1080#1083#1103' :'
  end
  object Label2: TLabel
    Left = 171
    Top = 138
    Width = 48
    Height = 16
    Caption = #1052#1072#1088#1082#1072' :'
  end
  object Label3: TLabel
    Left = 143
    Top = 177
    Width = 75
    Height = 16
    Caption = #1043#1086#1089'. '#1085#1086#1084#1077#1088' :'
  end
  object Label4: TLabel
    Left = 161
    Top = 217
    Width = 58
    Height = 16
    Alignment = taRightJustify
    Caption = #1079#1072' 1 '#1095#1072#1089' :'
  end
  object Label5: TLabel
    Left = 168
    Top = 276
    Width = 51
    Height = 16
    Alignment = taRightJustify
    Caption = #1079#1072' 1 '#1082#1084' :'
  end
  object Label8: TLabel
    Left = 49
    Top = 236
    Width = 94
    Height = 16
    Caption = #1090#1072#1088#1080#1092#1099' '#1078#1080#1083#1100#1077
  end
  object lbl1: TLabel
    Left = 129
    Top = 374
    Width = 91
    Height = 16
    Caption = #1055#1086#1083#1091#1087#1088#1080#1094#1077#1087#1099
  end
  object Label11: TLabel
    Left = 113
    Top = 49
    Width = 111
    Height = 16
    Caption = #1058#1080#1087' '#1090#1088#1072#1085#1089#1087#1086#1088#1090#1072' :'
  end
  object Label6: TLabel
    Left = 486
    Top = 338
    Width = 26
    Height = 16
    Caption = '+5%'
    Visible = False
  end
  object Label7: TLabel
    Left = 481
    Top = 368
    Width = 33
    Height = 16
    Caption = '+10%'
    Visible = False
  end
  object Edit3: TEdit
    Left = 228
    Top = 167
    Width = 227
    Height = 21
    TabOrder = 0
    OnKeyPress = Edit3KeyPress
  end
  object Edit4: TEdit
    Left = 228
    Top = 217
    Width = 227
    Height = 21
    TabOrder = 1
    OnKeyPress = Edit4KeyPress
  end
  object Edit5: TEdit
    Left = 228
    Top = 266
    Width = 227
    Height = 21
    TabOrder = 2
    OnKeyPress = Edit5KeyPress
  end
  object ComboBox1: TComboBox
    Left = 228
    Top = 89
    Width = 227
    Height = 24
    ItemHeight = 16
    TabOrder = 3
    OnKeyPress = ComboBox1KeyPress
  end
  object Edit1: TEdit
    Left = 228
    Top = 128
    Width = 227
    Height = 21
    TabOrder = 4
    OnKeyPress = Edit1KeyPress
  end
  object ComboBox2: TComboBox
    Left = 228
    Top = 49
    Width = 227
    Height = 24
    ItemHeight = 16
    ItemIndex = 0
    TabOrder = 5
    Text = #1040#1074#1090#1086#1090#1088#1072#1085#1089#1087#1086#1088#1090
    OnChange = ComboBox2Change
    OnKeyPress = ComboBox2KeyPress
    Items.Strings = (
      #1040#1074#1090#1086#1090#1088#1072#1085#1089#1087#1086#1088#1090
      #1052#1077#1093#1072#1085#1080#1079#1084#1099)
  end
  object Button1: TButton
    Left = 571
    Top = 561
    Width = 208
    Height = 41
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 6
    OnClick = Button1Click
  end
  object CheckListBox1: TCheckListBox
    Left = 228
    Top = 314
    Width = 226
    Height = 228
    ItemHeight = 16
    TabOrder = 7
  end
  object Edit2: TEdit
    Left = 492
    Top = 266
    Width = 228
    Height = 21
    TabOrder = 8
    Visible = False
  end
  object CheckBox1: TCheckBox
    Left = 492
    Top = 236
    Width = 120
    Height = 21
    Caption = #1052#1072#1096#1080#1085#1072' '#1095#1072#1089#1099
    TabOrder = 9
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 492
    Top = 305
    Width = 159
    Height = 21
    Caption = #1053#1072#1082#1088#1091#1090#1082#1080'  +5%, +10 %'
    TabOrder = 10
    OnClick = CheckBox2Click
  end
  object Edit6: TEdit
    Left = 522
    Top = 335
    Width = 149
    Height = 21
    TabOrder = 11
    Text = '0'
    Visible = False
    OnKeyPress = Edit6KeyPress
  end
  object Edit7: TEdit
    Left = 522
    Top = 364
    Width = 149
    Height = 21
    TabOrder = 12
    Text = '0'
    Visible = False
    OnKeyPress = Edit7KeyPress
  end
  object Database1: TDatabase
    AliasName = 'autopark2'
    SessionName = 'Default'
    Left = 480
    Top = 16
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 441
    Top = 16
  end
  object Query1: TQuery
    DatabaseName = 'autopark2'
    SQL.Strings = (
      'select DISTINCT Type from Cars ')
    Left = 520
    Top = 16
  end
  object Query2: TQuery
    DatabaseName = 'autopark2'
    SQL.Strings = (
      'select * from Cars ')
    Left = 560
    Top = 16
  end
end
