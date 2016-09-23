//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
   Form4->Query1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
  Form5->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
 Form4->Query1->Delete();
  
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button3Click(TObject *Sender)
{

 if (Form4->Button3->Caption == "Включить режим редактирования" )
   {

     Form4->Button3->Caption = "Отключить режим редактирования"  ;
     Form4->Label1->Visible=true;
     Form4->Button2->Visible=true;
     Form4->Button4->Visible=true;
     Form4->Query1->Close();
     Form4->Query1->RequestLive=true;
     Form4->Query1->Open();

   }
   else
   {   
     Form4->Label1->Visible=false;
     Form4->Button2->Visible=false;
     Form4->Button4->Visible=false;
     Form4->Button3->Caption="Включить режим редактирования";
     Form4->Query1->Close();
     Form4->Query1->RequestLive=false;
     Form4->Query1->Open();

   }

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button4Click(TObject *Sender)
{
Form4->Query1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::CheckBox1Click(TObject *Sender)
{
   if (CheckBox1->Checked==true)
   {
    ComboBox1->Visible=true;
    ComboBox2->Visible=true;
    CheckBox2->Visible=true;
    Button5->Visible=true;
    Button6->Visible=true;


    if( ComboBox1->ItemIndex==0)
     {
       // Если выбран автотранспорт
         Query2->Close();
         //Query1->SQL->Clear();
         //Query1->SQL->Add("select DISTINCT Type from Cars where Vidtr=True");
         Query2->Open();
         Query2->First();
          Form4->ComboBox2->Items->Clear();
         while ( !Query2->Eof)
          {
                 Form4->ComboBox2->Items->Add(Query2->FieldByName("Type")->AsString);
                 Query2->Next();
           }
          Form4->ComboBox2->ItemIndex=0;

     }
     else if( ComboBox1->ItemIndex==1)
     {
       // Если выбраны механизмы
         Query2->Close();
         Query2->SQL->Clear();
         Query2->SQL->Add("select DISTINCT Type from Cars where Vidtr=False");
         Query2->Open();
         Query2->First();
          Form4->ComboBox2->Items->Clear();
         while ( !Query2->Eof)
          {
                 Form4->ComboBox2->Items->Add(Query2->FieldByName("Type")->AsString);
                 Query2->Next();
           }
          Form4->ComboBox2->ItemIndex=0;

     }
     else
     {
     ShowMessage("Выберите катагорию автотранспорт или механизмы");
      return;

      }

   }
   else
   {
    ComboBox1->Visible=false;
    ComboBox2->Visible=false;
    CheckBox2->Visible=false;
    Button5->Visible=false;
    Button6->Visible=false;
    Button6->Click() ;
   }
}
//---------------------------------------------------------------------------



void __fastcall TForm4::Button5Click(TObject *Sender)
{

  if (CheckBox2->Checked==true)
   { Query1->Close();
     Query1->SQL->Clear();
         Query1->SQL->Add("select * from Cars where Vidtr=:p1 AND Type=:p2");
         if (ComboBox1->ItemIndex==0)
         Query1->ParamByName("p1")->AsBoolean = true;
         else
         Query1->ParamByName("p1")->AsBoolean = false;
         Query1->ParamByName("p2")->AsString = ComboBox2->Text;
       Query1->Open();
      }
      else
      { Query1->Close();
        Query1->SQL->Clear();
         Query1->SQL->Add("select * from Cars where Vidtr=:p1 ");
         if (ComboBox1->ItemIndex==0)
         Query1->ParamByName("p1")->AsBoolean = true;
         else
         Query1->ParamByName("p1")->AsBoolean = false;
       Query1->Open();
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button6Click(TObject *Sender)
{
 Query1->Close();
        Query1->SQL->Clear();
         Query1->SQL->Add("select * from Cars ");
          Query1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox1Change(TObject *Sender)
{
   if( ComboBox1->Text=="Автотранспорт")
     {
       // Если выбран автотранспорт
         Query2->Close();
         Query2->SQL->Clear();
         Query2->SQL->Add("select DISTINCT Type from Cars where Vidtr=True");
         Query2->Open();
         Query2->First();
          Form4->ComboBox2->Items->Clear();
         while ( !Query2->Eof)
          {
                 Form4->ComboBox2->Items->Add(Query2->FieldByName("Type")->AsString);
                 Query2->Next();
           }
          Form4->ComboBox2->ItemIndex=0;
            ShowMessage("автотранспорт ");

     }
     else if( ComboBox1->Text=="Механизмы")
     {
       // Если выбраны механизмы
         Query2->Close();
         Query2->SQL->Clear();
         Query2->SQL->Add("select DISTINCT Type from Cars where Vidtr=False");
         Query2->Open();
         Query2->First();
          Form4->ComboBox2->Items->Clear();
         while ( !Query2->Eof)
          {
                 Form4->ComboBox2->Items->Add(Query2->FieldByName("Type")->AsString);
                 Query2->Next();
           }
          Form4->ComboBox2->ItemIndex=0;
           ShowMessage(" механизмы");
     }
     else
     {
     ShowMessage("Выберите катагорию автотранспорт или механизмы");
      return;

      }

}
//---------------------------------------------------------------------------

