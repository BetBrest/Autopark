//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
        TMonthCalendar *MonthCalendar1;
        TButton *Button1;
        TEdit *Edit1;
        TLabel *Label1;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TComboBox *ComboBox3;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TComboBox *ComboBox4;
        TComboBox *ComboBox5;
        TLabel *Label5;
        TLabel *Label6;
        TComboBox *ComboBox6;
        TLabel *Label7;
        TEdit *Edit2;
        TEdit *Edit3;
        TComboBox *ComboBox7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TQuery *Query1;
        TDatabase *Database1;
        TDataSource *DataSource1;
        TQuery *Query2;
        TQuery *Query3;
        TLabel *Label11;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TLabel *Label12;
        TEdit *Edit8;
        TCheckBox *CheckBox1;
        TEdit *Edit9;
        TLabel *Label14;
        TLabel *Label15;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox4;
        TEdit *Edit10;
        TQuery *Query4;
        TComboBox *ComboBox8;
        TLabel *Label13;
        TEdit *Edit11;
        TEdit *Edit12;
        TEdit *Edit13;
        TCheckBox *CheckBox5;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TLabel *Label16;
        TComboBox *ComboBox9;
        void __fastcall MonthCalendar1Click(TObject *Sender);
        void __fastcall ComboBox1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ComboBox3KeyPress(TObject *Sender, char &Key);
        void __fastcall ComboBox2KeyPress(TObject *Sender, char &Key);
        void __fastcall ComboBox4KeyPress(TObject *Sender, char &Key);
        void __fastcall ComboBox5KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
        void __fastcall ComboBox6KeyPress(TObject *Sender, char &Key);
        void __fastcall ComboBox7KeyPress(TObject *Sender, char &Key);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall CheckBox4Click(TObject *Sender);
        void __fastcall Edit6KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit7KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit8KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Edit9KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ComboBox8KeyPress(TObject *Sender, char &Key);
        void __fastcall CheckBox5Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall Edit11KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit12KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ComboBox9KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm7(TComponent* Owner);
        bool flag_hours_or_km;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
