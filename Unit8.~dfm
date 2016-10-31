object Form8: TForm8
  Left = 380
  Top = 147
  BorderStyle = bsSingle
  Caption = #1054#1058#1063#1045#1058
  ClientHeight = 626
  ClientWidth = 1075
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 134
    Top = 8
    Width = 15
    Height = 13
    Caption = #1054#1058
  end
  object Label2: TLabel
    Left = 132
    Top = 189
    Width = 17
    Height = 13
    Caption = #1044#1054
  end
  object MonthCalendar1: TMonthCalendar
    Left = 48
    Top = 24
    Width = 191
    Height = 154
    Date = 40315.4979309491
    TabOrder = 0
  end
  object MonthCalendar2: TMonthCalendar
    Left = 48
    Top = 206
    Width = 191
    Height = 154
    Date = 40315.4979309491
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 256
    Top = 8
    Width = 665
    Height = 593
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Button1: TButton
    Left = 64
    Top = 416
    Width = 161
    Height = 49
    Caption = 'OK'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 64
    Top = 481
    Width = 161
    Height = 49
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1090#1077#1082#1089#1090#1086#1074#1099#1081' '#1092#1072#1081#1083
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 64
    Top = 544
    Width = 161
    Height = 49
    Caption = #1054#1090#1087#1088#1072#1074#1080#1090#1100' '#1074' Excel'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 944
    Top = 16
    Width = 113
    Height = 33
    Caption = #1052#1077#1093#1072#1085#1080#1079#1084#1099
    TabOrder = 6
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 944
    Top = 64
    Width = 113
    Height = 33
    Caption = #1056#1045#1045#1057#1058#1056
    TabOrder = 7
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 944
    Top = 112
    Width = 113
    Height = 33
    Caption = #1056#1077#1077#1089#1090#1088' '#1074' Excel'
    TabOrder = 8
    OnClick = Button6Click
  end
  object Database1: TDatabase
    AliasName = 'autopark2'
    SessionName = 'Default'
    Left = 24
    Top = 24
  end
  object Query1: TQuery
    DatabaseName = 'autopark2'
    SQL.Strings = (
      'select *  from Putlist where  (Date2 >= :p1) AND  (Date2 <= :p2)'
      
        'order by District , Object,  Vidtr, Marka, Govnumber, Pricep,Za1' +
        '_Km,Za1_Chv')
    Left = 24
    Top = 88
    ParamData = <
      item
        DataType = ftDate
        Name = 'p1'
        ParamType = ptUnknown
      end
      item
        DataType = ftDate
        Name = 'p2'
        ParamType = ptUnknown
      end>
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 24
    Top = 56
  end
  object Query2: TQuery
    DatabaseName = 'autopark2'
    SQL.Strings = (
      
        'select *  from Putlist where  (Date2 >= :p1) AND  (Date2 <= :p2)' +
        ' AND (Vidtr=True)'
      'order by Marka, Govnumber,Za1_Chv,Za1_Chn')
    Left = 1064
    Top = 16
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'p1'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'p2'
        ParamType = ptUnknown
      end>
  end
end
