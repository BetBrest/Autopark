object Form4: TForm4
  Left = 344
  Top = 115
  Width = 1000
  Height = 690
  Caption = #1052#1040#1064#1048#1053#1067
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 264
    Top = 8
    Width = 325
    Height = 16
    Caption = #1042#1085#1080#1084#1072#1085#1080#1077' '#1042#1082#1083#1102#1095#1077#1085' '#1088#1077#1078#1080#1084' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103' '#1079#1072#1087#1080#1089#1077#1081' !!!'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object DBGrid1: TDBGrid
    Left = 16
    Top = 32
    Width = 969
    Height = 513
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
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
        Expanded = False
        FieldName = 'Vidtr'
        Title.Caption = #1058#1088#1072#1085#1089#1087#1086#1088#1090
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Type'
        Title.Alignment = taCenter
        Title.Caption = #1058#1080#1087' '#1090#1088#1072#1085#1089#1087#1086#1088#1090#1072
        Width = 142
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Marka'
        Title.Alignment = taCenter
        Title.Caption = #1052#1072#1088#1082#1072
        Width = 100
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Govnumber'
        Title.Alignment = taCenter
        Title.Caption = #1043#1086#1089'. '#1085#1086#1084#1077#1088
        Width = 70
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Za1Chas'
        Title.Alignment = taCenter
        Title.Caption = ' '#1047#1072' 1 '#1095#1072#1089
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Za1Km'
        Title.Alignment = taCenter
        Title.Caption = #1047#1072' 1 '#1082#1084
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Za1Km_5'
        Title.Caption = #1047#1072' 1'#1082#1084' +5%'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Za1Km_10'
        Title.Caption = #1047#1072' 1'#1082#1084' +10%'
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Za1Chas_other'
        Title.Alignment = taCenter
        Title.Caption = #1047#1072' 1 '#1095#1072#1089' '#1087#1088#1086#1095
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'Za1MChas'
        Title.Alignment = taCenter
        Title.Caption = #1047#1072' 1 '#1084#1072#1096'/'#1095#1072#1089
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Pricep'
        Title.Caption = #1055#1088#1080#1094#1077#1087#1099
        Width = 140
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 14
    Top = 552
    Width = 203
    Height = 49
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 434
    Top = 552
    Width = 192
    Height = 49
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
    TabOrder = 2
    Visible = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 230
    Top = 552
    Width = 195
    Height = 49
    Caption = #1042#1082#1083#1102#1095#1080#1090#1100' '#1088#1077#1078#1080#1084' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 786
    Top = 552
    Width = 177
    Height = 49
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
    TabOrder = 4
    Visible = False
    OnClick = Button4Click
  end
  object ComboBox1: TComboBox
    Left = 128
    Top = 616
    Width = 153
    Height = 21
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 5
    Text = #1040#1074#1090#1086#1090#1088#1072#1085#1089#1087#1086#1088#1090
    Visible = False
    OnChange = ComboBox1Change
    Items.Strings = (
      #1040#1074#1090#1086#1090#1088#1072#1085#1089#1087#1086#1088#1090
      #1052#1077#1093#1072#1085#1080#1079#1084#1099)
  end
  object ComboBox2: TComboBox
    Left = 384
    Top = 616
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 6
    Visible = False
  end
  object Button5: TButton
    Left = 544
    Top = 616
    Width = 129
    Height = 25
    Caption = #1042#1082#1083#1102#1095#1080#1090#1100' '#1092#1080#1083#1100#1090#1088
    TabOrder = 7
    Visible = False
    OnClick = Button5Click
  end
  object CheckBox2: TCheckBox
    Left = 312
    Top = 616
    Width = 65
    Height = 17
    Caption = #1042#1080#1076' '#1090#1088
    TabOrder = 8
    Visible = False
  end
  object Button6: TButton
    Left = 688
    Top = 616
    Width = 121
    Height = 25
    Caption = #1054#1090#1082#1083#1102#1095#1080#1090#1100' '#1092#1080#1083#1100#1090#1088
    TabOrder = 9
    Visible = False
    OnClick = Button6Click
  end
  object CheckBox1: TCheckBox
    Left = 40
    Top = 616
    Width = 73
    Height = 17
    Caption = #1060#1080#1083#1100#1090#1088
    TabOrder = 10
    OnClick = CheckBox1Click
  end
  object Database1: TDatabase
    AliasName = 'autopark2'
    SessionName = 'Default'
    Left = 750
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 718
  end
  object Query1: TQuery
    DatabaseName = 'autopark2'
    SQL.Strings = (
      'select * from cars')
    Left = 790
    object Query1Vidtr: TBooleanField
      FieldName = 'Vidtr'
      Origin = 'AUTOPARK2."cars.DB".Vidtr'
      DisplayValues = #1040#1074#1090#1086#1090#1088#1072#1085#1089#1087#1086#1088#1090';'#1052#1077#1093#1072#1085#1080#1079#1084#1099
    end
    object Query1Govnumber: TStringField
      FieldName = 'Govnumber'
      Origin = 'AUTOPARK2."cars.DB".Govnumber'
      Size = 40
    end
    object Query1Marka: TStringField
      FieldName = 'Marka'
      Origin = 'AUTOPARK2."cars.DB".Marka'
      Size = 40
    end
    object Query1Type: TStringField
      FieldName = 'Type'
      Origin = 'AUTOPARK2."cars.DB".Type'
      Size = 40
    end
    object Query1Za1Chas: TFloatField
      FieldName = 'Za1Chas'
      Origin = 'AUTOPARK2."cars.DB".Za1Chas'
    end
    object Query1Za1Km: TFloatField
      FieldName = 'Za1Km'
      Origin = 'AUTOPARK2."cars.DB".Za1Km'
    end
    object Query1Za1Chas_other: TFloatField
      FieldName = 'Za1Chas_other'
      Origin = 'AUTOPARK2."cars.DB".Za1Chas_other'
    end
    object Query1Za1Km_other: TFloatField
      FieldName = 'Za1Km_other'
      Origin = 'AUTOPARK2."cars.DB".Za1Km_other'
    end
    object Query1Za1MChas: TFloatField
      FieldName = 'Za1MChas'
      Origin = 'AUTOPARK2."cars.DB".Za1MChas'
    end
    object Query1Pricep: TStringField
      FieldName = 'Pricep'
      Origin = 'AUTOPARK2."cars.DB".Pricep'
      Size = 255
    end
    object Query1Za1Km_5: TFloatField
      FieldName = 'Za1Km_5'
      Origin = 'AUTOPARK2."cars.DB".Za1Km_5'
    end
    object Query1Za1Km_10: TFloatField
      FieldName = 'Za1Km_10'
      Origin = 'AUTOPARK2."cars.DB".Za1Km_10'
    end
  end
  object Query2: TQuery
    DatabaseName = 'autopark2'
    SQL.Strings = (
      'select DISTINCT Type from Cars where Vidtr=True')
    Left = 40
  end
end