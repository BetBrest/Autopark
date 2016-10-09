object Form6: TForm6
  Left = 285
  Top = 154
  BorderStyle = bsSingle
  Caption = #1055#1059#1058#1045#1042#1067#1045' '#1051#1048#1057#1058#1067
  ClientHeight = 791
  ClientWidth = 1417
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 384
    Top = 20
    Width = 354
    Height = 16
    Caption = #1042#1085#1080#1084#1072#1085#1080#1077' '#1042#1082#1083#1102#1095#1077#1085' '#1088#1077#1078#1080#1084' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103' '#1079#1072#1087#1080#1089#1077#1081' !!!'
    Visible = False
  end
  object Label2: TLabel
    Left = 1250
    Top = 49
    Width = 143
    Height = 102
    Caption = 
      #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'#13#10'1 - '#1050#1080#1083#1086#1084#1077#1090#1088#1099', '#1095#1072#1089#1099#13#10'2 - '#1058#1086#1085#1085#1099'/'#1082#1080#1083#1086#1084#1077#1090#1088#1099#13#10'3 - '#1058#1086#1085 +
      #1085#1099#13#10'4 - '#1052#1072#1096#1080#1085#1072'/'#1095#1072#1089#1099#13#10
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 886
    Top = 738
    Width = 43
    Height = 16
    Caption = #1053#1086#1084#1077#1088
    Visible = False
  end
  object DBGrid1: TDBGrid
    Left = 20
    Top = 49
    Width = 1222
    Height = 582
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgMultiSelect]
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Date2'
        Title.Alignment = taCenter
        Title.Caption = #1044#1072#1090#1072
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'District'
        Title.Alignment = taCenter
        Title.Caption = #1056#1072#1081#1086#1085
        Width = 50
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Object'
        Title.Alignment = taCenter
        Title.Caption = #1054#1073#1098#1077#1082#1090
        Width = 100
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Type'
        Title.Alignment = taCenter
        Title.Caption = #1058#1080#1087' '#1090#1088#1072#1085#1089#1087#1086#1088#1090#1072
        Width = 130
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Marka'
        Title.Alignment = taCenter
        Title.Caption = #1052#1072#1088#1082#1072
        Width = 80
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Govnumber'
        Title.Alignment = taCenter
        Title.Caption = #1043#1086#1089'. '#1085#1086#1084#1077#1088
        Width = 60
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Za1_km'
        Title.Alignment = taCenter
        Title.Caption = #1047#1072' 1 '#1082#1084
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Km'
        Title.Alignment = taCenter
        Title.Caption = #1050#1084
        Width = 50
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Cost1'
        Title.Alignment = taCenter
        Title.Caption = #1062#1077#1085#1072' '#1079#1072' '#1082#1084
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Za1_ch'
        Title.Alignment = taCenter
        Title.Caption = #1047#1072' 1 '#1095#1072#1089
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Ch'
        Title.Alignment = taCenter
        Title.Caption = #1063#1072#1089#1086#1074
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Cost2'
        Title.Alignment = taCenter
        Title.Caption = #1062#1077#1085#1072' '#1079#1072' '#1095
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Vid_izm'
        Title.Caption = #1053#1072#1080#1084#1077#1085
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Zh'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Za1_chv'
        Title.Caption = #1047'/'#1087#1083' '#1079#1072' '#1095#1072#1089
        Width = 50
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Ch_v'
        Title.Caption = #1063#1072#1089#1086#1074' '#1079'/'#1087#1083
        Width = 50
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Pricep'
        Title.Alignment = taCenter
        Title.Caption = #1055#1088#1080#1094#1077#1087
        Width = 60
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 78
    Top = 650
    Width = 258
    Height = 60
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 649
    Top = 650
    Width = 258
    Height = 60
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 2
    Visible = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 363
    Top = 650
    Width = 259
    Height = 60
    Caption = #1042#1082#1083#1102#1095#1080#1090#1100' '#1088#1077#1078#1080#1084' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 926
    Top = 650
    Width = 178
    Height = 60
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '
    TabOrder = 4
    Visible = False
    OnClick = Button4Click
  end
  object CheckBox1: TCheckBox
    Left = 39
    Top = 738
    Width = 80
    Height = 21
    Caption = #1092#1080#1083#1100#1090#1088
    TabOrder = 5
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 118
    Top = 738
    Width = 60
    Height = 21
    Caption = #1056#1072#1077#1085
    TabOrder = 6
    Visible = False
    OnClick = CheckBox2Click
  end
  object ComboBox1: TComboBox
    Left = 177
    Top = 738
    Width = 179
    Height = 24
    ItemHeight = 16
    TabOrder = 7
    Visible = False
  end
  object CheckBox3: TCheckBox
    Left = 354
    Top = 738
    Width = 80
    Height = 21
    Caption = #1054#1073#1098#1077#1082#1090
    TabOrder = 8
    Visible = False
    OnClick = CheckBox3Click
  end
  object ComboBox2: TComboBox
    Left = 443
    Top = 738
    Width = 179
    Height = 24
    ItemHeight = 16
    TabOrder = 9
    Visible = False
  end
  object CheckBox4: TCheckBox
    Left = 630
    Top = 738
    Width = 80
    Height = 21
    Caption = #1052#1072#1088#1082#1072
    TabOrder = 10
    Visible = False
    OnClick = CheckBox4Click
  end
  object ComboBox3: TComboBox
    Left = 699
    Top = 738
    Width = 179
    Height = 24
    ItemHeight = 16
    TabOrder = 11
    Visible = False
    OnChange = ComboBox3Change
  end
  object ComboBox4: TComboBox
    Left = 935
    Top = 738
    Width = 179
    Height = 24
    ItemHeight = 16
    TabOrder = 12
    Visible = False
  end
  object Button5: TButton
    Left = 1142
    Top = 738
    Width = 92
    Height = 31
    Caption = 'OK'
    TabOrder = 13
    OnClick = Button5Click
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 768
    Top = 8
  end
  object Query1: TQuery
    Active = True
    DatabaseName = 'autopark2'
    SQL.Strings = (
      'select *  from Putlist')
    Left = 816
    Top = 8
    object Query1District: TStringField
      FieldName = 'District'
      Origin = 'AUTOPARK2."Putlist.DB".District'
      Size = 40
    end
    object Query1Object: TStringField
      FieldName = 'Object'
      Origin = 'AUTOPARK2."Putlist.DB".Object'
      Size = 40
    end
    object Query1Type: TStringField
      FieldName = 'Type'
      Origin = 'AUTOPARK2."Putlist.DB".Type'
      Size = 40
    end
    object Query1Govnumber: TStringField
      FieldName = 'Govnumber'
      Origin = 'AUTOPARK2."Putlist.DB".Govnumber'
      Size = 40
    end
    object Query1Marka: TStringField
      FieldName = 'Marka'
      Origin = 'AUTOPARK2."Putlist.DB".Marka'
      Size = 40
    end
    object Query1Pricep: TStringField
      FieldName = 'Pricep'
      Origin = 'AUTOPARK2."Putlist.DB".Pricep'
      Size = 40
    end
    object Query1Km: TFloatField
      FieldName = 'Km'
      Origin = 'AUTOPARK2."Putlist.DB".Km'
    end
    object Query1Ch: TFloatField
      FieldName = 'Ch'
      Origin = 'AUTOPARK2."Putlist.DB".Ch'
    end
    object Query1Cost1: TFloatField
      FieldName = 'Cost1'
      Origin = 'AUTOPARK2."Putlist.DB".Cost1'
    end
    object Query1Zh: TBooleanField
      DisplayLabel = #1046#1080#1083#1100#1077
      FieldName = 'Zh'
      Origin = 'AUTOPARK2."Putlist.DB".Zh'
      DisplayValues = #1046#1080#1083#1100#1077';'#1055#1088#1086#1095#1080#1077
    end
    object Query1Date2: TDateField
      FieldName = 'Date2'
      Origin = 'AUTOPARK2."Putlist.DB".Date2'
    end
    object Query1Cost2: TFloatField
      FieldName = 'Cost2'
      Origin = 'AUTOPARK2."Putlist.DB".Cost2'
    end
    object Query1Ch_v: TFloatField
      FieldName = 'Ch_v'
      Origin = 'AUTOPARK2."Putlist.DB".Ch_v'
    end
    object Query1Za1_chv: TFloatField
      FieldName = 'Za1_chv'
      Origin = 'AUTOPARK2."Putlist.DB".Za1_chv'
    end
    object Query1Za1_ch: TFloatField
      FieldName = 'Za1_ch'
      Origin = 'AUTOPARK2."Putlist.DB".Za1_ch'
    end
    object Query1Za1_km: TFloatField
      FieldName = 'Za1_km'
      Origin = 'AUTOPARK2."Putlist.DB".Za1_km'
    end
    object Query1Vid_izm: TFloatField
      FieldName = 'Vid_izm'
      Origin = 'AUTOPARK2."Putlist.DB".Vid_izm'
    end
  end
  object Database1: TDatabase
    AliasName = 'autopark2'
    SessionName = 'Default'
    Left = 720
    Top = 8
  end
  object Query2: TQuery
    DatabaseName = 'autopark2'
    SQL.Strings = (
      ''
      '')
    Left = 24
    Top = 536
  end
end
