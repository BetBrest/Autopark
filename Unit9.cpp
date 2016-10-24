//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm9::Edit1KeyPress(TObject *Sender, char &Key)
{

 if(Key == VK_RETURN )
 {
    Summa=StringSummaToFloat();
    Form9->Label1->Caption=FloatToStrF(Summa,ffFixed,10,2);
    if(Form7->flag_hours_or_km==true)
    {
     Form7->Edit3->Text=FloatToStrF(Summa,ffFixed,10,2);
     Form7->Edit3->SetFocus();
    }
    else
    {
     Form7->Edit2->Text=FloatToStrF(Summa,ffFixed,10,2);
     Form7->Edit2->SetFocus();
    }
    Form9->Visible=false;
 }
  if(Key == 0x2B )   // caps "+"
  {
   Summa=StringSummaToFloat();
   Form9->Label1->Caption=FloatToStrF(Summa,ffFixed,10,2);

  }

}
//---------------------------------------------------------------------------


float __fastcall TForm9::StringSummaToFloat()
{
 AnsiString  Str;
 float sum=0,count1;
 char symbol, number[10]="0";

 Str= Edit1->Text;
 for(int i=1,k=0;i<=Str.Length();i++,k++)
 {
  symbol=Str[i];
  if(symbol=='+')
  {
   count1=StrToFloat(number);
   sum+=count1;
   for(int j=0;j<10;j++) number[j]=0;
   k=-1;
  }
  else
  {
   number[k]=Str[i];

  }
 }
  count1=StrToFloat(number);
  sum+=count1;
// ShowMessage(count1);

 return  sum;
}
