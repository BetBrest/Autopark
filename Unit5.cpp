//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{


  }

//---------------------------------------------------------------------------


void __fastcall TForm5::ComboBox2Change(TObject *Sender)
{
///ShowMessage("!!");
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormActivate(TObject *Sender)
{
    Form5->ComboBox2->SetFocus();



}
//---------------------------------------------------------------------------

void __fastcall TForm5::ComboBox2KeyPress(TObject *Sender, char &Key)
{
    if(Key==VK_RETURN )
    {
     if( ComboBox2->ItemIndex==0)
     {
       // ���� ������ �������������
         Query1->Close();
         Query1->SQL->Clear();
         Query1->SQL->Add("select DISTINCT Type from Cars where Vidtr=True");
         Query1->Open();
         Query1->First();
          Form5->ComboBox1->Items->Clear();
         while ( !Query1->Eof)
          {
                 Form5->ComboBox1->Items->Add(Query1->FieldByName("Type")->AsString);
                 Query1->Next();
           }
          Form5->ComboBox1->ItemIndex=0;

     }
     else if( ComboBox2->ItemIndex==1)
     {
       // ���� ������� ���������
       Query1->Close();
         Query1->SQL->Clear();
         Query1->SQL->Add("select DISTINCT Type from Cars where Vidtr=False");
         Query1->Open();
         Query1->First();
          Form5->ComboBox1->Items->Clear();
         while ( !Query1->Eof)
          {
                 Form5->ComboBox1->Items->Add(Query1->FieldByName("Type")->AsString);
                 Query1->Next();
           }
          Form5->ComboBox1->ItemIndex=0;
     }
     else
     {
     ShowMessage("�������� ��������� ������������� ��� ���������");
      return;

     }




    Form5->ComboBox1->SetFocus();
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit1KeyPress(TObject *Sender, char &Key)
{
     if(Key == VK_RETURN )
    {
     Form5->Edit3->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ComboBox1KeyPress(TObject *Sender, char &Key)
{
  //ShowMessage(Form5->ComboBox1->Text);


    if(Key == VK_RETURN )
    {
       if (Form5->ComboBox2->Text=="�������������")
        {
          if (Form5->ComboBox1->Text=="��������� ������" || Form5->ComboBox1->Text=="c�������� ������")
          { // ��������� ����� ���������� ��� ������� ���� //
           // ShowMessage("������");
            Form5->Label8->Visible=true;
           Form5->lbl1->Visible=true;
           Form5->CheckListBox1->Visible=true;
          Form5->Label4->Caption="�� 1 ��� :" ;
          Form5->Label5->Caption="�� 1 �� :" ;


          }
           else
           {

               //   ShowMessage("����������");

            Form5->Label8->Visible=true;
           Form5->lbl1->Visible=false;
           Form5->CheckListBox1->Visible=false;
          Form5->Label4->Caption="�� 1 ��� :" ;
          Form5->Label5->Caption="�� 1 �� :" ;

          if (Form5->ComboBox1->Text=="�������������")
         {
          //ShowMessage("�������������");

          Form5->Label8->Visible=false;
           Form5->lbl1->Visible=false;
           Form5->CheckListBox1->Visible=false;
          Form5->Label4->Caption="�� 1 �����" ;
          Form5->Label5->Caption="�� 1 �/��" ;
          }


          }

         }

         else
          if (Form5->ComboBox2->Text=="���������")
         {
          ShowMessage("���������");

          Form5->Label8->Visible=false;
           Form5->lbl1->Visible=false;
           Form5->CheckListBox1->Visible=false;
          Form5->Label4->Caption="�� 1 ��� �����" ;
          Form5->Label5->Caption="�� 1 ��� ������" ;
          }
     Form5->Edit1->SetFocus();
    }
}
//---------------------------------------------------------------------------




void __fastcall TForm5::Edit3KeyPress(TObject *Sender, char &Key)
{

     if(Key == VK_RETURN )
    {
     Form5->Edit4->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit4KeyPress(TObject *Sender, char &Key)
{

     if(Key == VK_RETURN )
    {
     Form5->Edit5->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit5KeyPress(TObject *Sender, char &Key)
{

     if(Key == VK_RETURN )
    { if (Form5->ComboBox1->Text=="��������� ������" || Form5->ComboBox1->Text=="c�������� ������")

      {
       Form5->lbl1->Visible=true;
       Form5->CheckListBox1->Visible=true;

       Query1->Close();
         Query1->SQL->Clear();
         Query1->SQL->Add("select DISTINCT Marka from Cars where Type=\"�����������\"");
         Query1->Open();
         Query1->First();
           Form5->CheckListBox1->Items->Clear();
         while ( !Query1->Eof)
          {
                 Form5->CheckListBox1->Items->Add(Query1->FieldByName("Marka")->AsString);
                 Query1->Next();
           }

      }
    else
     { Form5->lbl1->Visible=false;
      Form5->CheckListBox1->Visible=false;
      Form5->Button1->SetFocus();

     }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender)
{
    Form5->Query2->Close();
    Query2->Open();

  if (Form5->ComboBox2->Text=="���������")
  { // ��������� ������ ��� ����������
      ShowMessage("��������� ������ ��� ����������");

     Form5->Query2->First();            // ���������� ��� �������� � ��������� ���� �����
   while ( !Form5->Query2->Eof)
      {

        if  (Form5->Query2->FieldByName("Marka") ->AsString == Form5->Edit1->Text && Form5->Query2->FieldByName("Govnumber") ->AsString == Form5->Edit3->Text)
       {
       ShowMessage("������ � ����� ������ ���������� !!!") ;

        return;
        }
         Form5->Query2->Next();
      }

    /// ���� �������� �������� ��������� ������
   Form5-> Query2->Close();


   Form5-> Query2->RequestLive=true;
   Form5->  Query2->Open();
        if(! Form5->Query2->Prepared)
    Form5->Query2->Prepare();




        Form5->Query2->Insert();


        Form5->Query2->FieldByName("Vidtr")->AsBoolean= false;
        Form5->Query2->FieldByName("Type")->AsString=  Form5->ComboBox1->Text;
        Form5->Query2->FieldByName("Marka")->AsString = Form5->Edit1->Text;
        Form5->Query2->FieldByName("Govnumber")->AsString = Form5->Edit3->Text;
        Form5->Query2->FieldByName("Za1chas")->AsFloat = StrToFloat(Form5->Edit4->Text);
        Form5->Query2->FieldByName("Za1chas_other")->AsFloat =  StrToFloat(Form5->Edit5->Text);
        Form5->Query2->Post();
  }
  else
  if (Form5->ComboBox1->Text=="��������� ������" && Form5->ComboBox2->Text=="�������������")
  { // ��������� ������ ��� �������
     ShowMessage("��������� ������ ��� �������");

    
          Form5->Query2->First();            // ���������� ��� �������� � ��������� ���� �����
   while ( !Form5->Query2->Eof)
      {

        if  (Form5->Query2->FieldByName("Marka") ->AsString == Form5->Edit1->Text && Form5->Query2->FieldByName("Govnumber") ->AsString == Form5->Edit3->Text)
       {
       ShowMessage("������ � ����� ������ ���������� !!!") ;

        return;
        }
         Form5->Query2->Next();
      }

    /// ���� �������� �������� ��������� ������
   Form5-> Query2->Close();


   Form5-> Query2->RequestLive=true;
   Form5->  Query2->Open();
        if(! Form5->Query2->Prepared)
    Form5->Query2->Prepare();




        Form5->Query2->Insert();


        Form5->Query2->FieldByName("Vidtr")->AsBoolean= true;
        Form5->Query2->FieldByName("Type")->AsString=  Form5->ComboBox1->Text;
        Form5->Query2->FieldByName("Marka")->AsString = Form5->Edit1->Text;
        Form5->Query2->FieldByName("Govnumber")->AsString = Form5->Edit3->Text;
        Form5->Query2->FieldByName("Za1chas")->AsFloat = StrToFloat(Form5->Edit4->Text);
        Form5->Query2->FieldByName("Za1km")->AsFloat =  StrToFloat(Form5->Edit5->Text);
        if (CheckBox2->Checked==true)
        {
          Form5->Query2->FieldByName("Za1km_5")->AsFloat =  StrToFloat(Form5->Edit6->Text);
          Form5->Query2->FieldByName("Za1km_10")->AsFloat =  StrToFloat(Form5->Edit7->Text);

        }

        if (CheckBox1->Checked==true)
         Form5->Query2->FieldByName("Za1MChas")->AsFloat =  StrToFloat(Form5->Edit2->Text);
      AnsiString pric="";
      for (int i =0;i< Form5->CheckListBox1->Items->Count; i++ )
      { if (CheckListBox1->Checked[i]==true)
        pric=pric  + CheckListBox1->Items->Strings[i]+ " ";

      }
       // ShowMessage(pric);
        Form5->Query2->FieldByName("Pricep")->AsString  = pric;

              Form5->Query2->Post();


  }
  else
   if (Form5->ComboBox1->Text!="��������� ������" && Form5->ComboBox2->Text=="�������������")
  { // ��������� ������ ��� ��������������
        ShowMessage(" ��������� ������ ��� ��������������");



          Form5->Query2->First();            // ���������� ��� �������� � ��������� ���� �����
   while ( !Form5->Query2->Eof)
      {

        if  (Form5->Query2->FieldByName("Marka") ->AsString == Form5->Edit1->Text && Form5->Query2->FieldByName("Govnumber") ->AsString == Form5->Edit3->Text)
       {
       ShowMessage("������ � ����� ������ ���������� !!!") ;

        return;
        }
         Form5->Query2->Next();
      }

    /// ���� �������� �������� ��������� ������
   Form5-> Query2->Close();


   Form5-> Query2->RequestLive=true;
   Form5->  Query2->Open();
        if(! Form5->Query2->Prepared)
    Form5->Query2->Prepare();




        Form5->Query2->Insert();


        Form5->Query2->FieldByName("Vidtr")->AsBoolean= true;
        Form5->Query2->FieldByName("Type")->AsString=  Form5->ComboBox1->Text;
        Form5->Query2->FieldByName("Marka")->AsString = Form5->Edit1->Text;
        Form5->Query2->FieldByName("Govnumber")->AsString = Form5->Edit3->Text;
        Form5->Query2->FieldByName("Za1chas")->AsFloat = StrToFloat(Form5->Edit4->Text);
        Form5->Query2->FieldByName("Za1km")->AsFloat =  StrToFloat(Form5->Edit5->Text);
         if (CheckBox2->Checked==true)
        {
          Form5->Query2->FieldByName("Za1km_5")->AsFloat =  StrToFloat(Form5->Edit6->Text);
          Form5->Query2->FieldByName("Za1km_10")->AsFloat =  StrToFloat(Form5->Edit7->Text);

        }
         if (CheckBox1->Checked==true)
         Form5->Query2->FieldByName("Za1MChas")->AsFloat =  StrToFloat(Form5->Edit2->Text);
        Form5->Query2->Post();


  }
ShowMessage("��������!") ;
Form5->Visible=false;
//�������� �������
Form4->Query1->Close();
Form4->Query1->Open();
}
//---------------------------------------------------------------------------







void __fastcall TForm5::CheckBox2Click(TObject *Sender)
{
  if (CheckBox2->Checked==true)
  {
   Edit6->Visible=true;
   Edit7->Visible=true;
   Label6->Visible=true;
   Label7->Visible=true;
    Form5->Edit6->SetFocus();
   }
  else
  {
  Edit6->Visible=false;
   Edit7->Visible=false;
   Label6->Visible=false;
   Label7->Visible=false;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm5::CheckBox1Click(TObject *Sender)
{
   if (CheckBox1->Checked==true)
  Edit2->Visible=true;
  else
  Edit2->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit6KeyPress(TObject *Sender, char &Key)
{
   if(Key == VK_RETURN )
    {
     Form5->Edit7->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit7KeyPress(TObject *Sender, char &Key)
{
   if(Key == VK_RETURN )
    {
     Form5->Button1->SetFocus();
    }
}
//---------------------------------------------------------------------------

