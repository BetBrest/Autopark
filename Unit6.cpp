//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button1Click(TObject *Sender)
{
    Form7->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button3Click(TObject *Sender)
{
 if (Form6->Button3->Caption == "Включить режим редактирования" )
   {
     Form6->Button3->Caption = "Отключить режим редактирования"  ;
     Form6->Label1->Visible=true;
     Form6->Button2->Visible=true;
      Form6->Button4->Visible=true;
     Form6->Query1->Close();
     Form6->Query1->RequestLive=true;
     Form6->Query1->Open();

   }

         else
   {
     Form6->Label1->Visible=false;
     Form6->Button2->Visible=false;
      Form6->Button4->Visible=false;
     Form6->Button3->Caption="Включить режим редактирования";
     Form6->Query1->Close();
     Form6->Query1->RequestLive=false;
     Form6->Query1->Open();

   }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender)
{
 Form6->Query1->Delete();

}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button4Click(TObject *Sender)
{
   Form6->Query1->Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TForm6::CheckBox1Click(TObject *Sender)
{
   if (CheckBox1->Checked==true)
   {
    ComboBox1->Visible=true;
    ComboBox2->Visible=true;
    ComboBox3->Visible=true;
    ComboBox4->Visible=true;
    CheckBox2->Visible=true;
    CheckBox3->Visible=true;
    CheckBox4->Visible=true;
    Label3->Visible=true;
    Button5->Visible=true;



    /*if( ComboBox1->ItemIndex==0)
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

      }    */

   }
   else
   {
    ComboBox1->Visible=false;
    ComboBox2->Visible=false;
    ComboBox3->Visible=false;
    ComboBox4->Visible=false;
    CheckBox2->Visible=false;
    CheckBox3->Visible=false;
    CheckBox4->Visible=false;
    Label3->Visible=false;
    Button5->Visible=false;


          Query1->Close();
         Query1->SQL->Clear();
         Query1->SQL->Add("select *  from Putlist ");
         Query1->Open();




    //Button6->Click() ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::CheckBox2Click(TObject *Sender)
{
     if (CheckBox2->Checked==true)
   {

         Query2->Close();
         Query2->SQL->Clear();
         Query2->SQL->Add("select DISTINCT District from Putlist ");
         Query2->Open();
         Query2->First();
          ComboBox1->Items->Clear();
         while ( !Query2->Eof)
          {
                 ComboBox1->Items->Add(Query2->FieldByName("District")->AsString);
                 Query2->Next();
           }
          ComboBox1->ItemIndex=0;
           Query2->Close();

     }

     else
   {
         ComboBox1->Items->Clear();
           ComboBox1->Clear();
    //Button6->Click() ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::CheckBox3Click(TObject *Sender)
{
     if (CheckBox3->Checked==true)
   {

         Query2->Close();
         Query2->SQL->Clear();
         Query2->SQL->Add("select DISTINCT Object from Putlist ");
         Query2->Open();
         Query2->First();
          ComboBox2->Items->Clear();
         while ( !Query2->Eof)
          {
                 ComboBox2->Items->Add(Query2->FieldByName("Object")->AsString);
                 Query2->Next();
           }
          ComboBox2->ItemIndex=0;
           Query2->Close();

     }

     else
   {
         ComboBox2->Items->Clear();
           ComboBox2->Clear();
    //Button6->Click() ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::CheckBox4Click(TObject *Sender)
{
    if (CheckBox4->Checked==true)
   {

         Query2->Close();
         Query2->SQL->Clear();
         Query2->SQL->Add("select DISTINCT Marka from Putlist ");
         Query2->Open();
         Query2->First();
          ComboBox3->Items->Clear();
         while ( !Query2->Eof)
          {
                 ComboBox3->Items->Add(Query2->FieldByName("Marka")->AsString);
                 Query2->Next();
           }
          ComboBox3->ItemIndex=0;
           Query2->Close();
            Query2->Close();
         Query2->SQL->Clear();
         Query2->SQL->Add("select DISTINCT Govnumber from Putlist where Marka =:p5 ");
         Query2->ParamByName("p5")->AsString=ComboBox3->Text;
         Query2->Open();
         Query2->First();
          ComboBox4->Items->Clear();
         while ( !Query2->Eof)
          {
                 ComboBox4->Items->Add(Query2->FieldByName("Govnumber")->AsString);
                 Query2->Next();
           }
          ComboBox4->ItemIndex=0;
           Query2->Close();


     }

     else
   {
         ComboBox3->Items->Clear();
           ComboBox3->Clear();
           ComboBox4->Items->Clear();
           ComboBox4->Clear();
    //Button6->Click() ;
   }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

/*void __fastcall TForm6::CheckBox5Click(TObject *Sender)
{   if (CheckBox5->Checked==true)
   {

         Query2->Close();
         Query2->SQL->Clear();
         Query2->SQL->Add("select DISTINCT Govnumber from Putlist where Marka =:p5 ");
         Query2->ParamByName("p5")->AsString=ComboBox3->Text;
         Query2->Open();
         Query2->First();
          ComboBox4->Items->Clear();
         while ( !Query2->Eof)
          {
                 ComboBox4->Items->Add(Query2->FieldByName("Govnumber")->AsString);
                 Query2->Next();
           }
          ComboBox4->ItemIndex=0;
           Query2->Close();

     }

     else
   {

           ComboBox4->Items->Clear();
           ComboBox4->Clear();
    //Button6->Click() ;
   }

}      */
//---------------------------------------------------------------------------

void __fastcall TForm6::ComboBox3Change(TObject *Sender)
{
      
         Query2->Close();
         Query2->SQL->Clear();
         Query2->SQL->Add("select DISTINCT Govnumber from Putlist where Marka =:p5 ");
         Query2->ParamByName("p5")->AsString=ComboBox3->Text;
         Query2->Open();
         Query2->First();
          ComboBox4->Items->Clear();
         while ( !Query2->Eof)
          {
                 ComboBox4->Items->Add(Query2->FieldByName("Govnumber")->AsString);
                 Query2->Next();
           }
          ComboBox4->ItemIndex=0;
           Query2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button5Click(TObject *Sender)
{

          if(CheckBox2->Checked==true && CheckBox3->Checked==true && CheckBox4->Checked==true )
        {
         Query1->Close();
         Query1->SQL->Clear();
         Query1->SQL->Add("select * from Putlist where District=:p1 AND Object =:p2 AND Marka =:p3 AND Govnumber =:p4");

         Query1->ParamByName("p1")->AsString=ComboBox1->Text;
         Query1->ParamByName("p2")->AsString=ComboBox2->Text;
         Query1->ParamByName("p3")->AsString=ComboBox3->Text;
         Query1->ParamByName("p4")->AsString=ComboBox4->Text;

         Query1->Open();
        }

          if(CheckBox2->Checked==true && CheckBox3->Checked==true && CheckBox4->Checked==false )
        {
         Query1->Close();
         Query1->SQL->Clear();
         Query1->SQL->Add("select * from Putlist where District=:p1 AND Object =:p2 ");

         Query1->ParamByName("p1")->AsString=ComboBox1->Text;
         Query1->ParamByName("p2")->AsString=ComboBox2->Text;
         Query1->Open();
        }

            if(CheckBox2->Checked==true && CheckBox3->Checked==false && CheckBox4->Checked==false )
        {
         Query1->Close();
         Query1->SQL->Clear();
         Query1->SQL->Add("select * from Putlist where District=:p1");

         Query1->ParamByName("p1")->AsString=ComboBox1->Text;

         Query1->Open();
        }

          if( CheckBox2->Checked==false && CheckBox3->Checked==false && CheckBox4->Checked==true )
        {
         Query1->Close();
         Query1->SQL->Clear();
         Query1->SQL->Add("select * from Putlist where Marka =:p3 AND Govnumber =:p4");


         Query1->ParamByName("p3")->AsString=ComboBox3->Text;
         Query1->ParamByName("p4")->AsString=ComboBox4->Text;

         Query1->Open();
        }

        //   Query2->Close();
}
//---------------------------------------------------------------------------

