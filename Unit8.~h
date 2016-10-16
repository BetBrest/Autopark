//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <QClipbrd.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
        TMonthCalendar *MonthCalendar1;
        TMonthCalendar *MonthCalendar2;
        TButton *Button1;
        TDatabase *Database1;
        TQuery *Query1;
        TDataSource *DataSource1;
        TButton *Button2;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button3;
        TButton *Button4;
        TQuery *Query2;
        TMemo *Memo1;
        TButton *Button5;
        TButton *Button6;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
  Variant App, Sh;
   void __fastcall toExcelCell(int c1,int c2, String data);
        void __fastcall toExcelCell(int c1,int c2, Variant data);
         void __fastcall toExcelCell2(int c1,int c2,String data);
         void __fastcall toExcelCell3(int c1,String data);
         
        // int printcar(n,f1,f2,f3,f4,f5,f6,f7,cc,ch,km,chas)
public:		// User declarations
        __fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
