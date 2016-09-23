//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//-----------------------------------------------------------



void __fastcall TForm3::FormActivate(TObject *Sender)
{
        Form3->ComboBox1->SetFocus();
         Form2->Query2->Close();
         Form2->Query2->SQL->Clear();
         Form2->Query2->SQL->Add("select DISTINCT District from Districs ");
         Form2->Query2->Open();
         Form2->Query2->First();
          Form3->ComboBox1->Items->Clear();
         while ( !Form2->Query2->Eof)
          {
                 Form3->ComboBox1->Items->Add(Form2->Query2->FieldByName("District")->AsString);
                 Form2->Query2->Next();
           }
          Form3->ComboBox1->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ComboBox1KeyPress(TObject *Sender, char &Key)
{
     if(Key == VK_RETURN )
    {
     Form3->Edit1->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit1KeyPress(TObject *Sender, char &Key)
{
   if(Key == VK_RETURN )
    {
     Form3->Button1->Click();
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
    if (Edit1->Text=="")
    {
      ShowMessage("Вы не ввели объект!!!");
      return;
    }
    Form2->Query1->Close();
    Form2->Query1->SQL->Clear();
    Form2->Query1->SQL->Add("select * from Districs")   ;
      Form2->Query1->Open();


     Form2->Query1->First();            // перебираем все элементы и проверяем есть такие
   while ( !Form2->Query1->Eof)
      {

        if  (Form2->Query1->FieldByName("District") ->AsString == Form3->ComboBox1->Text && Form2->Query1->FieldByName("Objects") ->AsString == Form3->Edit1->Text)
       {
       ShowMessage("Объект с таким именем существует !!!") ;

        return;
        }
         Form2->Query1->Next();
      }

    /// если проверка пройдена добавляем объект
   Form2-> Query1->Close();


   Form2-> Query1->RequestLive=true;
   Form2->  Query1->Open();
        if(! Form2->Query1->Prepared)
    Form2->Query1->Prepare();




        Form2->Query1->Insert();

        Form2->Query1->FieldByName("District")->AsString=  Form3->ComboBox1->Text;
        Form2->Query1->FieldByName("Objects")->AsString = Form3->Edit1->Text;

        Form2->Query1->Post();

       Form3->Visible=false;

   Form2-> Query1->RequestLive=false;
    Form2-> Query1->Refresh();
}
//---------------------------------------------------------------------------

