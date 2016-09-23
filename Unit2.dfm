object Form2: TForm2
  Left = 343
  Top = 194
  Width = 963
  Height = 554
  Caption = #1056#1072#1081#1086#1085#1099' '#1080' '#1086#1073#1098#1077#1082#1090#1099
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 223
    Top = 24
    Width = 393
    Height = 18
    Caption = #1042#1085#1080#1084#1072#1085#1080#1077' '#1042#1082#1083#1102#1095#1077#1085' '#1088#1077#1078#1080#1084' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103' '#1079#1072#1087#1080#1089#1077#1081' !!!'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Button1: TButton
    Left = 745
    Top = 56
    Width = 200
    Height = 49
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 745
    Top = 176
    Width = 200
    Height = 49
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 1
    Visible = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 744
    Top = 112
    Width = 201
    Height = 49
    Caption = #1042#1082#1083#1102#1095#1080#1090#1100' '#1088#1077#1078#1080#1084' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
    TabOrder = 2
    OnClick = Button3Click
  end
  object DBGrid1: TDBGrid
    Left = 23
    Top = 56
    Width = 705
    Height = 417
    DataSource = DataSource1
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'District'
        Title.Alignment = taCenter
        Title.Caption = #1056#1040#1049#1054#1053
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Objects'
        Title.Alignment = taCenter
        Title.Caption = #1054#1041#1066#1045#1050#1058
        Width = 480
        Visible = True
      end>
  end
  object Button4: TButton
    Left = 744
    Top = 240
    Width = 201
    Height = 49
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080#1079#1084#1077#1085#1077#1085#1080#1077
    TabOrder = 4
    Visible = False
    OnClick = Button4Click
  end
  object Query1: TQuery
    Active = True
    DatabaseName = 'autopark2'
    SQL.Strings = (
      'select * from Districs')
    Left = 808
    Top = 8
  end
  object Database1: TDatabase
    AliasName = 'autopark2'
    SessionName = 'Default'
    Left = 736
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 776
    Top = 8
  end
  object Query2: TQuery
    DatabaseName = 'autopark2'
    Left = 840
    Top = 8
  end
end
