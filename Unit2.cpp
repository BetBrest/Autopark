//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
Form3->Visible=true;
Form3->Edit1->Clear();




}
//---------------------------------------------------------------------------}

//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Form1->Visible = true;
}
//---------------------------------------------------------------------------














void __fastcall TForm2::Button2Click(TObject *Sender)
{
   Query1->Delete();     
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button3Click(TObject *Sender)
{
if (Form2->Button3->Caption == "Включить режим редактирования" )
   {

     Form2->Button3->Caption = "Отключить режим редактирования"  ;
     Form2->Label1->Visible=true;
     Form2->Button2->Visible=true;
     Form2->Button4->Visible=true;
     Form2->Query1->Close();
     Form2->Query1->RequestLive=true;
     Form2->Query1->Open();

   }
   else
   {
     Form2->Label1->Visible=false;
     Form2->Button2->Visible=false;
     Form2->Button4->Visible=false;
     Form2->Button3->Caption="Включить режим редактирования";
     Form2->Query1->Close();
     Form2->Query1->RequestLive=false;
     Form2->Query1->Open();

   }        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{

 Query1->Refresh();
}
//---------------------------------------------------------------------------

