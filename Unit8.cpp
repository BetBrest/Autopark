//---------------------------------------------------------------------------

#include <vcl.h>
#include <ComObj.hpp>
#include <math.h>


#pragma hdrstop

#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int printcar(int, BOOL ,int,AnsiString,AnsiString,AnsiString,AnsiString,AnsiString,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float) ;


void __fastcall TForm8::toExcelCell3(int Row, AnsiString data)
{

  try {

    int xlCenter = 0xFFFFEFF4;
   Variant  cur = Sh.OlePropertyGet("Range", Sh.OlePropertyGet("Cells", Row,1), Sh.OlePropertyGet("Cells",Row,7));
       cur.OleProcedure("Select");
      cur.OleProcedure("Merge");
   cur.OlePropertySet("Value", data.c_str());
   cur.OlePropertySet("HorizontalAlignment", xlCenter); //��������� �� ���.

  } catch(...) { ; }
}/* toExcelCell() */
//------------------------------------------------------------------------
void __fastcall TForm8::toExcelCell2(int Row,int Column, AnsiString data)
{
  try {
    Variant  cur = Sh.OlePropertyGet("Cells", Row,Column);
       cur.OleProcedure("Select");
       Clipboard()->AsText = data;
       cur.OleProcedure("PasteSpecial");

  } catch(...) { ; }
}/* toExcelCell() */
//------------------------------------------------------------------------

void __fastcall TForm8::toExcelCell(int Row,int Column, AnsiString data)
{
  try {
    Variant  cur = Sh.OlePropertyGet("Cells", Row,Column);
    cur.OlePropertySet("Value", data.c_str());
  } catch(...) { ; }
}/* toExcelCell() */
//------------------------------------------------------------------------

void __fastcall TForm8::toExcelCell(int Row,int Column, Variant data)
{
  try {
    Variant  cur = Sh.OlePropertyGet("Cells", Row,Column);
    cur.OlePropertySet("Value", data);
  } catch(...) { ; }
}/* toExcelCell() */


void __fastcall TForm8::Button1Click(TObject *Sender)    // �������� ������ ��
{
float s1_ob=0, // ���� �� ������
s1_r=0, //    ���� �� PA���
s1_v=0, //    ���� �� Vidtr
s1_all=0;   // ���� �� ������ �� ���� �������


float s1_m=0,s2_m=0; // ���� �� ������
float sv=0; // ��������� � � �������
float ch=0    ; // ���� � �������� ���
float cc=0; // ���� �� ���  ���.
float chas=0,km=0;
int n=1; // ����� �/�

int vid_izm; /// ����������� (�,��,�,�/�)
float ed_tkm=0,ed_t=0,ed_mch=0;
float sum_tkm=0,sum_t=0,sum_mch=0;
float col_tkm=0,col_t=0,col_mch=0;

AnsiString Vyhodnoy[100];  // ������ � ��������� �����
int count_vyh=0;


Form8->Memo1->Clear();
if (Form8->MonthCalendar1->Date > Form8->MonthCalendar2->Date)
{
  ShowMessage("���� '��'  �� ����� ��������� '��'!!!") ;
  return;
}


 Query1->Close();
Memo1->Lines->Add("����� � " + DateToStr(Form8->MonthCalendar1->Date ) + " �� " + DateToStr(Form8->MonthCalendar2->Date )+":") ;
Query1->ParamByName("p1")->AsDate =Form8->MonthCalendar1->Date;
Query1->ParamByName("p2")->AsDate =Form8->MonthCalendar2->Date;
Query1->Open();

if   ( Query1->Eof)
{  ShowMessage ("��� �� ����� ������!");

return;

}

  AnsiString     f1,f2,f3,f4,f5;
  float f6,f7;   // ������  �� ���/ �� ��
  float           differ=0;
  BOOL           vidtr;

                      f1= Query1->FieldByName("District")->AsString;
                      f2= Query1->FieldByName("Object")->AsString ;
                      vidtr=Query1->FieldByName("Vidtr")->AsBoolean;
                      f3= Query1->FieldByName("Marka")->AsString;
                      f4= Query1->FieldByName("Govnumber")->AsString;
                      f5= Query1->FieldByName("Pricep")->AsString ;
                      f6=Query1->FieldByName("Za1_ch")->AsFloat;
                      f7=Query1->FieldByName("Za1_km")->AsFloat;
                      cc= Query1->FieldByName("Za1_Chv")->AsFloat;
                    //  vid_izm=Query1->FieldByName("Vid_izm")->AsInteger;
                    //  chas=Query1->FieldByName("Ch")->AsInteger;
                    //  km=Query1->FieldByName("Km")->AsInteger;


                        Memo1->Lines->Add("����");
                        Memo1->Lines->Add( f1 );
                        Memo1->Lines->Add("������");
                        Memo1->Lines->Add( f2 );
                        Memo1->Lines->Add( "" );
                        if (vidtr==true)
                        Memo1->Lines->Add("���������" );



         while ( !Query1->Eof)

           {

           if (f1== Query1->FieldByName("District")->AsString  )
             {
               if (f2== Query1->FieldByName("Object")->AsString  )
                  {
                     if (vidtr == Query1->FieldByName("Vidtr")->AsBoolean  )
                       {
                       // ������� ��� ���� ����������

           /*testtt*/        /*    if(f7==Query1->FieldByName("Za1_km")->AsFloat )
                                   sv=1;
                                   else
                                   sv=2;
                                   ShowMessage(FloatToStr(f7-Query1->FieldByName("Za1_km")->AsFloat) ) ;  */

                      differ =  Query1->FieldByName("Za1_km")->AsFloat;
                       if (f3== Query1->FieldByName("Marka")->AsString && f4==Query1->FieldByName("Govnumber")->AsString && f5== Query1->FieldByName("Pricep")->AsString  && f7==differ )
                        {
                          if ( cc!= Query1->FieldByName("Za1_Chv")->AsFloat)      // ����   ������ ����� � �������� ��� ����� ������ ������ � ����� ���������
                          {
                             if ((cc*ch)!=0)    // ����� ��� ����
                               {
                                Vyhodnoy[count_vyh]=".\t �/��. � ��� ���� \t ���  \t � \t" + FloatToStrF(cc,ffFixed, 10, 2) + "\t"  + FloatToStrF(ch, ffFixed, 10, 2) + "\t" +  FloatToStrF(cc*ch,ffFixed, 10, 2);
                               //Form8->Memo1->Lines->Add(IntToStr(n) +".\t �/��. � ��� ���� \t ���  \t � \t" + IntToStr(cc) + "\t"  + FloatToStrF(ch, ffGeneral, 4, 2) + "\t" +  IntToStr(int(cc*ch)));
                               //  n++;
                               sv=sv+ cc*ch;
                               count_vyh++;
                               }
                             ch=0;

                          }
                           vid_izm=  Query1->FieldByName("Vid_izm")->AsInteger;

                          if(vid_izm==1)
                         { s1_m= s1_m + Query1->FieldByName("Cost1")->AsFloat;   //��
                          s2_m= s2_m + Query1->FieldByName("Cost2")->AsFloat;    //����
                          chas=chas+Query1->FieldByName("Ch")->AsFloat;
                          km=km+Query1->FieldByName("Km")->AsFloat;

                          f6=Query1->FieldByName("Za1_ch")->AsFloat;
                          f7=Query1->FieldByName("Za1_km")->AsFloat;


                          }
                          if(vid_izm==2)
                         { sum_tkm= sum_tkm + Query1->FieldByName("Cost1")->AsFloat;   //��
                           col_tkm=col_tkm + Query1->FieldByName("Km")->AsFloat;
                           ed_tkm = Query1->FieldByName("Za1_km")->AsFloat;

                          }
                           if(vid_izm==3)
                         { sum_t= sum_t + Query1->FieldByName("Cost1")->AsFloat;   //��
                           col_t=col_t + Query1->FieldByName("Km")->AsFloat;
                           ed_t = Query1->FieldByName("Za1_km")->AsFloat;

                          }
                           if(vid_izm==4)
                         { sum_mch= sum_mch + Query1->FieldByName("Cost1")->AsFloat;   //��
                           col_mch=col_mch + Query1->FieldByName("Km")->AsFloat;
                           ed_mch =  Query1->FieldByName("Za1_km")->AsFloat;

                          }


                          if(Query1->FieldByName("Ch_v")->AsFloat!=0)
                          {ch= ch+Query1->FieldByName("Ch_v")->AsFloat;
                          cc= Query1->FieldByName("Za1_Chv")->AsFloat;
                           }

                        }
                        else
                        {      /// ������ ���������� � ����������
                              n= printcar( n , vidtr , vid_izm, f1,f2,f3,f4, f5, f6, f7, cc, ch, km, chas, s1_m, s2_m,sum_mch,sum_tkm,sum_t,ed_mch,ed_t,ed_tkm,col_mch,col_t,col_tkm)   ;
                              if(count_vyh)
                              { for (int h=0;h<count_vyh; h++)
                                 {Memo1->Lines->Add(IntToStr(n) + Vyhodnoy[h]);
                                  n++;
                                  }
                                 count_vyh=0;
                               }
                             s1_v+=s1_m + s2_m + cc*ch + sum_tkm + sum_t + sum_mch+sv;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=km=0;
                             sum_mch=sum_tkm=sum_t=ed_mch=ed_t=ed_tkm=col_mch=col_t=col_tkm=sv=0;


                             f3= Query1->FieldByName("Marka")->AsString;
                             f4= Query1->FieldByName("Govnumber")->AsString;
                             f5= Query1->FieldByName("Pricep")->AsString ;
                             f6=f7=0;
                             f6=Query1->FieldByName("Za1_ch")->AsFloat;
                             f7=float(Query1->FieldByName("Za1_km")->AsFloat);
                             chas=Query1->FieldByName("Ch")->AsFloat;
                             km=Query1->FieldByName("Km")->AsFloat;
                             vid_izm=Query1->FieldByName("Vid_izm")->AsInteger;

                             if(vid_izm==1)
                              {
                                s1_m=  Query1->FieldByName("Cost1")->AsFloat;
                                s2_m=  Query1->FieldByName("Cost2")->AsFloat;

                              }

                              ch=Query1->FieldByName("Ch_v")->AsFloat;
                              cc=Query1->FieldByName("Za1_Chv")->AsFloat;
                              if(vid_izm==2)
                              {
                                sum_tkm=  Query1->FieldByName("Cost1")->AsFloat;   //��
                                col_tkm= Query1->FieldByName("Km")->AsFloat;
                                ed_tkm = Query1->FieldByName("Za1_km")->AsFloat;
                              }
                               if(vid_izm==3)
                                { sum_t= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_t= Query1->FieldByName("Km")->AsFloat;
                                  ed_t = Query1->FieldByName("Za1_km")->AsFloat;
                                }
                                if(vid_izm==4)
                                { sum_mch= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_mch= Query1->FieldByName("Km")->AsFloat;
                                  ed_mch =  Query1->FieldByName("Za1_km")->AsFloat;
                                }

                         }

                     }
                     else
                     {
                                  /// ������ ���������� � ����������
                             n= printcar( n , vidtr , vid_izm, f1,f2,f3,f4, f5, f6, f7, cc, ch, km, chas, s1_m, s2_m,sum_mch,sum_tkm,sum_t,ed_mch,ed_t,ed_tkm,col_mch,col_t,col_tkm)   ;
                             if(count_vyh)
                              { for (int h=0;h<count_vyh; h++)
                                 {Memo1->Lines->Add(IntToStr(n) + Vyhodnoy[h]);
                                  n++;
                                  }
                                 count_vyh=0;
                               }

                              s1_v+=s1_m + s2_m + cc*ch + sum_tkm + sum_t + sum_mch+sv;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=km=0;
                             sum_mch=sum_tkm=sum_t=ed_mch=ed_t=ed_tkm=col_mch=col_t=col_tkm=sv=0;

                        Memo1->Lines->Add("");
                        Memo1->Lines->Add( "\t �����: \t\t\t\t\t   "+ FloatToStrF(s1_v,ffFixed, 10, 2) );      /// ����� ���� �� ����������
                        Memo1->Lines->Add("");
                              n=1;
                              s1_ob+=s1_v;    // ���� ��������� ������
                              s1_v=0;

                        if (Query1->FieldByName("Vidtr")->AsBoolean==true)
                        Memo1->Lines->Add("���������" );
                        vidtr= Query1->FieldByName("Vidtr")->AsBoolean;

                             f3= Query1->FieldByName("Marka")->AsString;
                             f4= Query1->FieldByName("Govnumber")->AsString;
                             f5= Query1->FieldByName("Pricep")->AsString ;
                             f6=Query1->FieldByName("Za1_ch")->AsFloat;
                             f7=Query1->FieldByName("Za1_km")->AsFloat;
                             chas=Query1->FieldByName("Ch")->AsFloat;
                             km=Query1->FieldByName("Km")->AsFloat;
                             vid_izm=Query1->FieldByName("Vid_izm")->AsInteger;


                               if(vid_izm==1)
                              {
                                s1_m=  Query1->FieldByName("Cost1")->AsFloat;
                                s2_m=  Query1->FieldByName("Cost2")->AsFloat;

                              }

                             ch=Query1->FieldByName("Ch_v")->AsFloat;
                             cc=Query1->FieldByName("Za1_Chv")->AsFloat;
                              if(vid_izm==2)
                              {
                                sum_tkm=  Query1->FieldByName("Cost1")->AsFloat;   //��
                                col_tkm= Query1->FieldByName("Km")->AsFloat;
                                ed_tkm = Query1->FieldByName("Za1_km")->AsFloat;
                              }
                               if(vid_izm==3)
                                { sum_t= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_t= Query1->FieldByName("Km")->AsFloat;
                                  ed_t = Query1->FieldByName("Za1_km")->AsFloat;
                                }
                                if(vid_izm==4)
                                { sum_mch= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_mch= Query1->FieldByName("Km")->AsFloat;
                                  ed_mch =  Query1->FieldByName("Za1_km")->AsFloat;
                                }

                     }

                   }

                  else
                  {       /// ������ ���������� � ����������
                              n= printcar( n , vidtr , vid_izm, f1,f2,f3,f4, f5, f6, f7, cc, ch, km, chas, s1_m, s2_m,sum_mch,sum_tkm,sum_t,ed_mch,ed_t,ed_tkm,col_mch,col_t,col_tkm)   ;
                                if(count_vyh)
                              { for (int h=0;h<count_vyh; h++)
                                 {Memo1->Lines->Add(IntToStr(n) + Vyhodnoy[h]);
                                  n++;
                                  }
                                 count_vyh=0;
                               }
                             s1_v+=s1_m + s2_m + cc*ch + sum_tkm + sum_t + sum_mch+sv;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=km=0;
                             sum_mch=sum_tkm=sum_t=ed_mch=ed_t=ed_tkm=col_mch=col_t=col_tkm=sv=0;

                              Memo1->Lines->Add("");
                              Memo1->Lines->Add( "\t �����: \t\t\t\t\t "+ FloatToStrF(s1_v,ffFixed,10,2) );   /// ����� ���� �� ����������
                              n=1;
                              s1_ob+=s1_v;    // ���� ��������� ������
                              s1_v=0;

                               Memo1->Lines->Add( "\t �����: \t\t\t\t\t "+ FloatToStrF(s1_ob,ffFixed,10,2) );
                               Memo1->Lines->Add("");
                              s1_r+=s1_ob;    // ���� ������ ������
                              s1_ob=0;


                      Memo1->Lines->Add("������");
                      Memo1->Lines->Add( Query1->FieldByName("Object")->AsString);
                      Memo1->Lines->Add( "" );

                       if (Query1->FieldByName("Vidtr")->AsBoolean==true)
                        Memo1->Lines->Add("���������" );


                     f2=  Query1->FieldByName("Object")->AsString;
                      vidtr= Query1->FieldByName("Vidtr")->AsBoolean;

                             f3= Query1->FieldByName("Marka")->AsString;
                             f4= Query1->FieldByName("Govnumber")->AsString;
                             f5= Query1->FieldByName("Pricep")->AsString ;
                             f6=Query1->FieldByName("Za1_ch")->AsFloat;
                             f7=Query1->FieldByName("Za1_km")->AsFloat;
                             //f8=Query1->FieldByName("Ch")->AsInteger;
                             //f9=Query1->FieldByName("Km")->AsInteger;
                             chas=Query1->FieldByName("Ch")->AsFloat;
                             km=Query1->FieldByName("Km")->AsFloat;
                             vid_izm=Query1->FieldByName("Vid_izm")->AsInteger;

                               if(vid_izm==1)
                              {
                                s1_m=  Query1->FieldByName("Cost1")->AsFloat;
                                s2_m=  Query1->FieldByName("Cost2")->AsFloat;

                              }
                              ch=Query1->FieldByName("Ch_v")->AsFloat;
                              cc=Query1->FieldByName("Za1_Chv")->AsFloat;
                               if(vid_izm==2)
                              {
                                sum_tkm=  Query1->FieldByName("Cost1")->AsFloat;   //��
                                col_tkm= Query1->FieldByName("Km")->AsFloat;
                                ed_tkm = Query1->FieldByName("Za1_km")->AsFloat;
                              }
                               if(vid_izm==3)
                                { sum_t= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_t= Query1->FieldByName("Km")->AsFloat;
                                  ed_t = Query1->FieldByName("Za1_km")->AsFloat;
                                }
                                if(vid_izm==4)
                                { sum_mch= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_mch= Query1->FieldByName("Km")->AsFloat;
                                  ed_mch =  Query1->FieldByName("Za1_km")->AsFloat;
                                }


                  }


             }
             else
             {         /// ������ ���������� � ����������
                            n= printcar( n , vidtr, vid_izm, f1,f2,f3,f4, f5, f6, f7, cc, ch, km, chas, s1_m, s2_m,sum_mch,sum_tkm,sum_t,ed_mch,ed_t,ed_tkm,col_mch,col_t,col_tkm)   ;
                                if(count_vyh)
                              { for (int h=0;h<count_vyh; h++)
                                 {Memo1->Lines->Add(IntToStr(n) + Vyhodnoy[h]);
                                  n++;
                                  }
                                 count_vyh=0;
                               }

                            s1_v+=s1_m + s2_m + cc*ch + sum_tkm + sum_t + sum_mch+sv;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=km=0;
                             sum_mch=sum_tkm=sum_t=ed_mch=ed_t=ed_tkm=col_mch=col_t=col_tkm=0,sv=0;

                              Memo1->Lines->Add("");
                              Memo1->Lines->Add( "\t �����: \t\t\t\t\t  "+ FloatToStrF(s1_v,ffFixed,10,2) );   /// ����� ���� �� ����������

                              n=1;
                              s1_ob+=s1_v;    // ���� ��������� ������
                              s1_v=0;

                                  Memo1->Lines->Add( "\t �����: \t\t\t\t\t "+ FloatToStrF(s1_ob,ffFixed,10,2) );
                                Memo1->Lines->Add("");
                               s1_r+=s1_ob;    // ���� ������ ������
                              s1_ob=0;

                               Memo1->Lines->Add( "\t ����� �� ������: \t\t\t\t\t  "+ FloatToStrF(s1_r,ffFixed,10,2) );
                              s1_all+=s1_r;    // ���� ���� ������
                              s1_r=0;

                 //����� ����� ����
                Memo1->Lines->Add("����" );
                Memo1->Lines->Add(Query1->FieldByName("District")->AsString);



                Memo1->Lines->Add("������");
                Memo1->Lines->Add( Query1->FieldByName("Object")->AsString);
                Memo1->Lines->Add( "" );

                  if (Query1->FieldByName("Vidtr")->AsBoolean==true)
                  Memo1->Lines->Add("���������" );


                f1=  Query1->FieldByName("District")->AsString;
                f2=  Query1->FieldByName("Object")->AsString;
                vidtr= Query1->FieldByName("Vidtr")->AsBoolean;



                             f3= Query1->FieldByName("Marka")->AsString;
                             f4= Query1->FieldByName("Govnumber")->AsString;
                             f5= Query1->FieldByName("Pricep")->AsString ;
                             f6=Query1->FieldByName("Za1_ch")->AsFloat;
                             f7=Query1->FieldByName("Za1_km")->AsFloat;
                             chas=Query1->FieldByName("Ch")->AsFloat;
                             km=Query1->FieldByName("Km")->AsFloat;
                             //f8=Query1->FieldByName("Ch")->AsInteger;
                             //f9=Query1->FieldByName("Km")->AsInteger;
                             vid_izm=Query1->FieldByName("Vid_izm")->AsInteger;

                               if(vid_izm==1)
                              {
                                s1_m=  Query1->FieldByName("Cost1")->AsFloat;
                                s2_m=  Query1->FieldByName("Cost2")->AsFloat;

                              }
                              ch=Query1->FieldByName("Ch_v")->AsFloat;
                              cc=Query1->FieldByName("Za1_Chv")->AsFloat;
                               if(vid_izm==2)
                              {
                                sum_tkm=  Query1->FieldByName("Cost1")->AsFloat;   //��
                                col_tkm= Query1->FieldByName("Km")->AsFloat;
                                ed_tkm = Query1->FieldByName("Za1_km")->AsFloat;
                              }
                               if(vid_izm==3)
                                { sum_t= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_t= Query1->FieldByName("Km")->AsFloat;
                                  ed_t = Query1->FieldByName("Za1_km")->AsFloat;
                                }
                                if(vid_izm==4)
                                { sum_mch= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_mch= Query1->FieldByName("Km")->AsFloat;
                                  ed_mch =  Query1->FieldByName("Za1_km")->AsFloat;
                                }


             }
              Query1->Next();
           }


              // ���� ���� ������� ������� ����
               {
                      /// ������ ���������� � ����������
                    n= printcar( n , vidtr , vid_izm, f1,f2,f3,f4, f5, f6, f7, cc, ch, km, chas, s1_m, s2_m,sum_mch,sum_tkm,sum_t,ed_mch,ed_t,ed_tkm,col_mch,col_t,col_tkm)   ;
                  /*      if(count_vyh)
                              { for (int h=0;h<count_vyh; h++)
                                 {Memo1->Lines->Add(IntToStr(n) + Vyhodnoy[h]);
                                  n++;
                                  }
                                 count_vyh=0;
                               }     */
                            /// s1_v+=s1_m + s2_m + cc*ch;    // ���� ������ ������
                            /// s1_m=s2_m=cc=ch=chas=km=0;

                             s1_v+=s1_m + s2_m + cc*ch + sum_tkm + sum_t + sum_mch;//+sv;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=km=0;
                             sum_mch=sum_tkm=sum_t=ed_mch=ed_t=ed_tkm=col_mch=col_t=col_tkm=sv=0;


                              Memo1->Lines->Add("");
                              Memo1->Lines->Add( "\t �����: \t\t\t\t\t   "+ FloatToStrF(s1_v,ffFixed,10,2) );   /// ����� ���� �� ����������
                              n=1;
                              s1_ob+=s1_v;    // ���� ��������� ������
                              s1_v=0;

                                  Memo1->Lines->Add( "\t �����: \t\t\t\t\t "+ FloatToStrF(s1_ob,ffFixed,10,2) );
                              Memo1->Lines->Add("");
                              s1_r+=s1_ob;    // ���� ������ ������
                              s1_ob=0;

                              Memo1->Lines->Add( "\t ����� �� ������: \t\t\t\t\t  "+ FloatToStrF(s1_r,ffFixed,10,2) );
                              //Memo1->Lines->Add( "�� �����: "+ IntToStr(s1_r) );
                              s1_all+=s1_r;    // ���� ���� ������
                              s1_r=0;
               }



            Memo1->Lines->Add("");
            Memo1->Lines->Add("����� �� ����� : " + FloatToStrF(s1_all,ffFixed,10,2));
            Memo1->Lines->Add("");

            Query1->Close();


   }








   //---------------------------------------------------------------------------

void __fastcall TForm8::Button2Click(TObject *Sender)    //��������� ������
{
String a;
TStringList *List = new TStringList;
List->Add(Memo1->Text);
List->SaveToFile(ExtractFilePath(Application->ExeName)+"//������//" + DateToStr(Date())+ ".txt");
ShowMessage("������ ������� ��������� � ����� ������");
}
//---------------------------------------------------------------------------







void __fastcall TForm8::Button3Click(TObject *Sender)    //��������� � ������
{


    // ������������� ���� � ����� �������
     AnsiString sFile = ExtractFilePath(Application->ExeName)+"\\ACT.xlt";

     // �������������� Excel, ��������� ���� ������
     try {
       App=Variant::GetActiveObject("Excel.Application");
     } catch(...) {
     try { App=Variant::CreateObject("Excel.Application"); }
     catch (...) {
      Application->MessageBox("���������� ������� Microsoft Excel!"
      " �������� ����� ���������� �� ���������� �� �����������.","������",MB_OK+MB_ICONERROR);
        }}
     try {
      App.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
      Sh=App.OlePropertyGet("WorkSheets",1);
     } catch(...) {
      Application->MessageBox("������ �������� ������� Microsoft Excel!","������",MB_OK+MB_ICONERROR);
     }

// ������� �-�� �������*****************************************************************************************
 // ������� ������� ��� ������������ �������  �� ������ ����� +�����(2�������) + ������ ����� �� �������
  int blank=0;
    int i=0,j=0;
    for( i=0;i<Memo1->Lines->Count;i++)
   { if (Memo1->Lines->Strings[i]=="����")
    {
      i= i+3;
    blank++ ;
    ///������ ����� �������
    while(i!=Memo1->Lines->Count )
     { if (Memo1->Lines->Strings[i]=="����")
       {
         i--;
         j=0;
         break;
       }
     i++;
      j++;
      if(j==89)
      { blank++;
        j=0;
      }

     }

    }

    }

    if (Memo1->Lines->Strings[1]=="���������")
    {

    blank++ ;
    i=2         ;
    ///������ ����� �������
    while(i!=Memo1->Lines->Count )
     {
     i++;
      j++;
      if(j==89)
      { blank++;
        j=0;
      }

     }

    }


    ShowMessage("����� �������: " + IntToStr(blank));
    if(blank==0)
    {
    ShowMessage("��� ������  ��� ������������! ");
    return;
    }

//������� ������ ��� ����������**********************************************************************

          Sh = Sh.OlePropertyGet("Range", "A1:G108");//�������
      Sh.OleProcedure("Select"); //
        Sh.OleProcedure("Copy");
   // blank=5;
Variant v = App.OlePropertyGet("WorkSheets",1);
int d;
for (int k=109; k<blank*109;k+=109)
{
v=v.OlePropertyGet("Cells", 109,1);
     v.OleProcedure("PasteSpecial");
}
//��������� ��������� ������********************************************************************************************
    // App.OlePropertySet("Visible",true);
        i=0; j=0;    blank=0;
        AnsiString zakaz;

         for( i=0;i<Memo1->Lines->Count;i++)
  {

    if (Memo1->Lines->Strings[i]=="����")
    {   i++;
       toExcelCell(1+blank,1,String("�������� " + Memo1->Lines->Strings[i]));
       zakaz =    Memo1->Lines->Strings[i];
        i++;
         m1:
    while(i!=Memo1->Lines->Count )
     {

       if (Memo1->Lines->Strings[i]=="����")
       {
          i++;
          blank=blank+108;
         toExcelCell(1+blank,1,String("�������� " + Memo1->Lines->Strings[i]));
          zakaz =    Memo1->Lines->Strings[i];
            i++;
         j=0;
         goto m1;
       }

        if (Memo1->Lines->Strings[i]=="������")
        { i++;
          toExcelCell3(15+j+blank,Memo1->Lines->Strings[i])    ;
          j++;
          i++;
             if(j==40)
                j=43;
                if (j==91)
               {

                blank=blank+108;
                j=0;

              }


        }

       toExcelCell2(15+j+blank,1, Memo1->Lines->Strings[i])   ;

     i++;
      j++;
      if(j==40)
      j=43;
      if (j==91)
      {

          blank=blank+108;
         toExcelCell(1+blank,1,String("�������� " + zakaz));

         j=0;
         goto m1;
      }

     }



    }



   }
   if (Memo1->Lines->Strings[1]=="���������")
       {  j=0;
          blank=0;
         i=1;

    while(i!=Memo1->Lines->Count )
     {




       toExcelCell2(15+j+blank,1, Memo1->Lines->Strings[i])   ;

      i++;
      j++;
      if(j==40)
      j=43;
      if (j==91)
      {

          blank=blank+108;
                j=0;

      }

     }

     // ShowMessage("Exit") ;

    }



  App.OlePropertySet("Visible",true);
  // ����������� �������
    Sh.Clear();
    App.Clear();



}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button4Click(TObject *Sender)       //���������
{


float s1_v=0; //    ���� �� Vidtr

float s1_m=0,s2_m=0; // ���� �� ������
float ch=0;   // ���� �� ���  ���.
float cc=0; // ���� �� ���  ���.
int n=1; // ����� �/�
float sv=0;// ����� �� ��� ���
float chas =0;
float cost_chas=0;// ������� ���� � ������

AnsiString Vyhodnoy[100];  // ������ � ��������� �����
int count_vyh=0;


Form8->Memo1->Clear();
if (Form8->MonthCalendar1->Date > Form8->MonthCalendar2->Date)
{
  ShowMessage("���� '��'  �� ����� ��������� '��'!!!") ;
  return;
}


 Query2->Close();
Memo1->Lines->Add("����� � " + DateToStr(Form8->MonthCalendar1->Date ) + " �� " + DateToStr(Form8->MonthCalendar2->Date )+":") ;
Query2->ParamByName("p1")->AsDate =Form8->MonthCalendar1->Date;
Query2->ParamByName("p2")->AsDate =Form8->MonthCalendar2->Date;
Query2->Open();

if   ( Query2->Eof)
{  ShowMessage ("��� �� ����� ������!");

return;

}



  AnsiString     f3,f4,f5;
  float f6;   // ������  �� ���/ �� ��
  BOOL           vidtr;


                      f3= Query2->FieldByName("Marka")->AsString;
                      f4= Query2->FieldByName("Govnumber")->AsString;
                      f5= Query2->FieldByName("Pricep")->AsString ;
                      cc= Query2->FieldByName("Za1_Chv")->AsFloat;
                  //    f6=Query2->FieldByName("Za1_ch")->AsInteger;





                        Memo1->Lines->Add("���������" );
         while ( !Query2->Eof)

           {



                     if (f3== Query2->FieldByName("Marka")->AsString && f4==Query2->FieldByName("Govnumber")->AsString )
                        {
                          if ( cc!= Query2->FieldByName("Za1_Chv")->AsFloat)      // ����   ������ ����� � �������� ��� ����� ������ ������ � ����� ���������
                          {
                             if ((cc*ch)!=0)    // ����� ��� ����
                               {
                                Vyhodnoy[count_vyh]=".\t �/��. � ��� ���� \t ���  \t � \t" + FloatToStrF(cc,ffFixed,10,2) + "\t"  + FloatToStrF(ch, ffFixed, 10, 2) + "\t" +  FloatToStrF(cc*ch,ffFixed,10,2);
                               //Form8->Memo1->Lines->Add(IntToStr(n) +".\t �/��. � ��� ���� \t ���  \t � \t" + IntToStr(cc) + "\t"  + FloatToStrF(ch, ffGeneral, 4, 2) + "\t" +  IntToStr(int(cc*ch)));
                               //  n++;
                               sv=sv+ cc*ch;
                               count_vyh++;
                               }
                             ch=0;

                          }

                          chas=chas+Query2->FieldByName("Ch")->AsFloat;
                          cost_chas=Query2->FieldByName("Za1_ch")->AsFloat;
                          s1_m= s1_m + Query2->FieldByName("Cost1")->AsFloat;   //��
                          s2_m= s2_m + Query2->FieldByName("Cost2")->AsFloat;    //����
                          if(Query2->FieldByName("Ch_v")->AsFloat!=0)
                          {ch= ch+Query2->FieldByName("Ch_v")->AsFloat;
                          cc= Query2->FieldByName("Za1_Chv")->AsFloat;
                           }
                        }
                        else
                        {


                                         // ���� ��������� ����� ��� ������
                                  Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 + " "  "\t ��� " + " \t � \t" + FloatToStrF(cost_chas,ffFixed,10,2) + "\t"  + FloatToStrF(chas, ffFixed, 10, 2) + "\t" +  FloatToStrF(s2_m,ffFixed,10,2));
                                    n++;


                               if ((cc*ch)!=0)    // ����� ��� ����
                               {Memo1->Lines->Add(IntToStr(n) +".\t �/��. � ��� ���� \t ���  \t � \t" + FloatToStrF(cc,ffFixed,10,2) + "\t"  + FloatToStrF(ch, ffFixed, 10, 2) + "\t" +  FloatToStrF(cc*ch,ffFixed,10,2));
                                 n++;
                                  if(count_vyh)
                              { for (int h=0;h<count_vyh; h++)
                                 {Memo1->Lines->Add(IntToStr(n) + Vyhodnoy[h]);
                                  n++;
                                  }
                                 count_vyh=0;
                               }

                               }
                             s1_v+=s1_m + s2_m + cc*ch +sv;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=cost_chas=sv=0;




                             f3= Query2->FieldByName("Marka")->AsString;
                             f4= Query2->FieldByName("Govnumber")->AsString;
                             f5= Query2->FieldByName("Pricep")->AsString ;
                             chas=Query2->FieldByName("Ch")->AsFloat;
                             cost_chas=Query2->FieldByName("Za1_ch")->AsFloat;


                             s1_m=  Query2->FieldByName("Cost1")->AsFloat;
                             s2_m=  Query2->FieldByName("Cost2")->AsFloat;
                              ch=Query2->FieldByName("Ch_v")->AsFloat;
                              cc=Query2->FieldByName("Za1_Chv")->AsFloat;
                         }



            Query2->Next()  ;
           }

                     // ���� ��������� ����� ��� ������
                                  Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 + " "  "\t ��� " + " \t � \t" + FloatToStrF(cost_chas,ffFixed,10,2) + "\t"  + FloatToStrF(chas, ffFixed, 10, 2) + "\t" +  FloatToStrF(s2_m, ffFixed,10,2));
                                    n++;


                               if ((cc*ch)!=0)    // ����� ��� ����
                               {Memo1->Lines->Add(IntToStr(n) +".\t �/��. � ��� ���� \t ���  \t � \t" + FloatToStrF(cc, ffFixed,10,2) + "\t"  + FloatToStrF(ch, ffFixed, 10, 2) + "\t" +  FloatToStrF(cc*ch,ffFixed,10,2));
                                 n++;
                                   if(count_vyh)
                              { for (int h=0;h<count_vyh; h++)
                                 {Memo1->Lines->Add(IntToStr(n) + Vyhodnoy[h]);
                                  n++;
                                  }
                                 count_vyh=0;
                               }
                               }
            Query2->Close();


}
//---------------------------------------------------------------------------


void __fastcall TForm8::Button5Click(TObject *Sender)        //������
{
float s1_ob=0, // ���� �� ������
s1_r=0, //    ���� �� PA���
s1_v=0, //    ���� �� Vidtr
s1_all=0;   // ���� �� ������ �� ���� �������
float s1_m=0,s2_m=0; // ���� �� ������
float sv=0; // ����� �� �������� ���
float ch=0;    // ���� �� ���  ���.
float cc=0; // ���� �� ���  ���.
float chas=0,km=0;
int n=1; // ����� �/�
int vid_izm; /// ����������� (�,��,�,�/�)

float sum_tkm=0,sum_t=0,sum_mch=0;
float col_tkm=0,col_t=0,col_mch=0;


Form8->Memo1->Clear();
if (Form8->MonthCalendar1->Date > Form8->MonthCalendar2->Date)
{
  ShowMessage("���� '��'  �� ����� ��������� '��'!!!") ;
  return;
}


 Query1->Close();
Memo1->Lines->Add("����� � " + DateToStr(Form8->MonthCalendar1->Date ) + " �� " + DateToStr(Form8->MonthCalendar2->Date )+":") ;
Memo1->Lines->Add("������");
Query1->ParamByName("p1")->AsDate =Form8->MonthCalendar1->Date;
Query1->ParamByName("p2")->AsDate =Form8->MonthCalendar2->Date;
Query1->Open();

if   ( Query1->Eof)
{  ShowMessage ("��� �� ����� ������!");

return;

}



  AnsiString     f1,f2,f3,f4,f5;
 // int f6,f7;   // ������  �� ���/ �� ��
  BOOL           vidtr;

                      f1= Query1->FieldByName("District")->AsString;
                      f2= Query1->FieldByName("Object")->AsString ;
                      vidtr=Query1->FieldByName("Vidtr")->AsBoolean;
                      f3= Query1->FieldByName("Marka")->AsString;
                      f4= Query1->FieldByName("Govnumber")->AsString;
                      f5= Query1->FieldByName("Pricep")->AsString ;
                       cc= Query1->FieldByName("Za1_Chv")->AsFloat;


                       Memo1->Lines->Add( IntToStr(n)+ ". \t" + f1 + " � ��� �����, ");
                        n++;

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

         while ( !Query1->Eof)

           {

           if (f1== Query1->FieldByName("District")->AsString  )
             {
               if (f2== Query1->FieldByName("Object")->AsString  )
                  {
                     if (vidtr == Query1->FieldByName("Vidtr")->AsBoolean  )
                       {
                       // ������� ��� ���� ����������
                       if (f3== Query1->FieldByName("Marka")->AsString && f4==Query1->FieldByName("Govnumber")->AsString && f5== Query1->FieldByName("Pricep")->AsString )
                        {
                           vid_izm=  Query1->FieldByName("Vid_izm")->AsInteger;

                           if ( cc!= Query1->FieldByName("Za1_Chv")->AsFloat)      // ����   ������ ����� � �������� ��� ����� ������ ������ � ����� ���������
                          {
                             if ((cc*ch)!=0)    // ����� ��� ����
                               {
                                sv=sv+cc*ch;
                                ch=0;

                               }


                          }

                          if(vid_izm==1)
                         { s1_m= s1_m + Query1->FieldByName("Cost1")->AsFloat;   //��
                          s2_m= s2_m + Query1->FieldByName("Cost2")->AsFloat;    //����
                          chas=chas+Query1->FieldByName("Ch")->AsFloat;
                          km=km+Query1->FieldByName("Km")->AsFloat;

                          }
                          if(vid_izm==2)
                         { sum_tkm= sum_tkm + Query1->FieldByName("Cost1")->AsFloat;   //��
                           col_tkm=col_tkm + Query1->FieldByName("Km")->AsFloat;
                      //     ed_tkm = Query1->FieldByName("Za1_km")->AsInteger;

                          }
                           if(vid_izm==3)
                         { sum_t= sum_t + Query1->FieldByName("Cost1")->AsFloat;   //��
                           col_t=col_t + Query1->FieldByName("Km")->AsFloat;
                     //      ed_t = Query1->FieldByName("Za1_km")->AsInteger;

                          }
                           if(vid_izm==4)
                         { sum_mch= sum_mch + Query1->FieldByName("Cost1")->AsFloat;   //��
                           col_mch=col_mch + Query1->FieldByName("Km")->AsFloat;
                        //   ed_mch =  Query1->FieldByName("Za1_km")->AsInteger;

                          }


                          if(Query1->FieldByName("Ch_v")->AsFloat!=0)
                          {ch= ch+Query1->FieldByName("Ch_v")->AsFloat;
                          cc= Query1->FieldByName("Za1_Chv")->AsFloat;
                           }


                        }
                        else
                        {      /// ������ ���������� � ����������
                            //  n= printcar( n , vidtr , vid_izm, f1,f2,f3,f4, f5, f6, f7, cc, ch, km, chas, s1_m, s2_m,sum_mch,sum_tkm,sum_t,ed_mch,ed_t,ed_tkm,col_mch,col_t,col_tkm)   ;

                             s1_v+=s1_m + s2_m  + cc*ch + sum_tkm + sum_t + sum_mch+sv;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=km=0;
                             sum_mch=sum_tkm=sum_t=col_mch=col_t=col_tkm=sv=0;



                              //s1_ob+=s1_v;    // ���� ��������� ������
                             // s1_v=0;

                             f3= Query1->FieldByName("Marka")->AsString;
                             f4= Query1->FieldByName("Govnumber")->AsString;
                             f5= Query1->FieldByName("Pricep")->AsString ;


                             chas=Query1->FieldByName("Ch")->AsFloat;
                             km=Query1->FieldByName("Km")->AsFloat;
                             vid_izm=Query1->FieldByName("Vid_izm")->AsInteger;




                            // s1_m=  Query1->FieldByName("Cost1")->AsInteger;
                           //  s2_m=  Query1->FieldByName("Cost2")->AsInteger;
                              ch=Query1->FieldByName("Ch_v")->AsFloat;
                              cc=Query1->FieldByName("Za1_Chv")->AsFloat;

                                 if(vid_izm==1)
                              {
                                s1_m=  Query1->FieldByName("Cost1")->AsFloat;
                                s2_m=  Query1->FieldByName("Cost2")->AsFloat;

                              }


                              if(vid_izm==2)
                              {
                                sum_tkm=  Query1->FieldByName("Cost1")->AsFloat;   //��
                                col_tkm= Query1->FieldByName("Km")->AsFloat;
                              //  ed_tkm = Query1->FieldByName("Za1_km")->AsInteger;
                              }
                               if(vid_izm==3)
                                { sum_t= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_t= Query1->FieldByName("Km")->AsFloat;
                                //  ed_t = Query1->FieldByName("Za1_km")->AsInteger;
                                }
                                if(vid_izm==4)
                                { sum_mch= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_mch= Query1->FieldByName("Km")->AsFloat;
                                //  ed_mch =  Query1->FieldByName("Za1_km")->AsInteger;
                                }


                         }


                     }
                     else
                     {
                                  /// ������ ���������� � ����������
                          //   n= printcar( n , vidtr , vid_izm, f1,f2,f3,f4, f5, f6, f7, cc, ch, km, chas, s1_m, s2_m,sum_mch,sum_tkm,sum_t,ed_mch,ed_t,ed_tkm,col_mch,col_t,col_tkm)   ;

                              s1_v+=s1_m + s2_m + cc*ch + sum_tkm + sum_t + sum_mch+sv;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=km=0;
                             sum_mch=sum_tkm=sum_t=col_mch=col_t=col_tkm=sv=0;



                              s1_ob+=s1_v;    // ���� ��������� ������
                              s1_v=0;


                        vidtr= Query1->FieldByName("Vidtr")->AsBoolean;




                             f3= Query1->FieldByName("Marka")->AsString;
                             f4= Query1->FieldByName("Govnumber")->AsString;
                             f5= Query1->FieldByName("Pricep")->AsString ;

                             chas=Query1->FieldByName("Ch")->AsFloat;
                             km=Query1->FieldByName("Km")->AsFloat;
                             vid_izm=Query1->FieldByName("Vid_izm")->AsInteger;


                           //  s1_m=  Query1->FieldByName("Cost1")->AsInteger;
                            // s2_m=  Query1->FieldByName("Cost2")->AsInteger;
                             ch=Query1->FieldByName("Ch_v")->AsFloat;
                             cc=Query1->FieldByName("Za1_Chv")->AsFloat;

                                  if(vid_izm==1)
                              {
                                s1_m=  Query1->FieldByName("Cost1")->AsFloat;
                                s2_m=  Query1->FieldByName("Cost2")->AsFloat;

                              }


                              if(vid_izm==2)
                              {
                                sum_tkm=  Query1->FieldByName("Cost1")->AsFloat;   //��
                                col_tkm= Query1->FieldByName("Km")->AsFloat;
                              //  ed_tkm = Query1->FieldByName("Za1_km")->AsInteger;
                              }
                               if(vid_izm==3)
                                { sum_t= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_t= Query1->FieldByName("Km")->AsFloat;
                              //    ed_t = Query1->FieldByName("Za1_km")->AsInteger;
                                }
                                if(vid_izm==4)
                                { sum_mch= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_mch= Query1->FieldByName("Km")->AsFloat;
                                //  ed_mch =  Query1->FieldByName("Za1_km")->AsInteger;
                                }
                     }

                   }

                  else
                  {       /// ������ ���������� � ����������
                         //     n= printcar( n , vidtr , vid_izm, f1,f2,f3,f4, f5, f6, f7, cc, ch, km, chas, s1_m, s2_m,sum_mch,sum_tkm,sum_t,ed_mch,ed_t,ed_tkm,col_mch,col_t,col_tkm)   ;

                             s1_v+=s1_m + s2_m + cc*ch + sum_tkm + sum_t + sum_mch+sv;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=km=0;
                             sum_mch=sum_tkm=sum_t=col_mch=col_t=col_tkm=sv=0;



                              s1_ob+=s1_v;    // ���� ��������� ������
                              s1_v=0;

                               Memo1->Lines->Add( "\t" + f2 + "\t\t\t\t\t "+ FloatToStrF(s1_ob,ffFixed,12,2) );
                             //  Memo1->Lines->Add("");
                              s1_r+=s1_ob;    // ���� ������ ������
                              s1_ob=0;




                     f2=  Query1->FieldByName("Object")->AsString;
                      vidtr= Query1->FieldByName("Vidtr")->AsBoolean;

                             f3= Query1->FieldByName("Marka")->AsString;
                             f4= Query1->FieldByName("Govnumber")->AsString;
                             f5= Query1->FieldByName("Pricep")->AsString ;

                             //f8=Query1->FieldByName("Ch")->AsInteger;
                             //f9=Query1->FieldByName("Km")->AsInteger;
                             chas=Query1->FieldByName("Ch")->AsFloat;
                             km=Query1->FieldByName("Km")->AsFloat;
                             vid_izm=Query1->FieldByName("Vid_izm")->AsInteger;

                           //  s1_m=  Query1->FieldByName("Cost1")->AsInteger;
                           //  s2_m=  Query1->FieldByName("Cost2")->AsInteger;
                              ch=Query1->FieldByName("Ch_v")->AsFloat;
                              cc=Query1->FieldByName("Za1_Chv")->AsFloat;

                                    if(vid_izm==1)
                              {
                                s1_m=  Query1->FieldByName("Cost1")->AsFloat;
                                s2_m=  Query1->FieldByName("Cost2")->AsFloat;

                              }

                               if(vid_izm==2)
                              {
                                sum_tkm=  Query1->FieldByName("Cost1")->AsFloat;   //��
                                col_tkm= Query1->FieldByName("Km")->AsFloat;
                             //   ed_tkm = Query1->FieldByName("Za1_km")->AsInteger;
                              }
                               if(vid_izm==3)
                                { sum_t= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_t= Query1->FieldByName("Km")->AsFloat;
                             //     ed_t = Query1->FieldByName("Za1_km")->AsInteger;
                                }
                                if(vid_izm==4)
                                { sum_mch= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_mch= Query1->FieldByName("Km")->AsFloat;
                                //  ed_mch =  Query1->FieldByName("Za1_km")->AsInteger;
                                }


                  }


             }
             else
             {         /// ������ ���������� � ����������
                       //     n= printcar( n , vidtr, vid_izm, f1,f2,f3,f4, f5, f6, f7, cc, ch, km, chas, s1_m, s2_m,sum_mch,sum_tkm,sum_t,ed_mch,ed_t,ed_tkm,col_mch,col_t,col_tkm)   ;


                            s1_v+=s1_m + s2_m + cc*ch + sum_tkm + sum_t + sum_mch+sv;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=km=0;
                             sum_mch=sum_tkm=sum_t=col_mch=col_t=col_tkm=sv=0;




                              s1_ob+=s1_v;    // ���� ��������� ������
                              s1_v=0;

                                  Memo1->Lines->Add( "\t" + f2 + "\t\t\t\t\t "+ FloatToStrF(s1_ob,ffFixed,12,2)  );
                            //    Memo1->Lines->Add("");
                               s1_r+=s1_ob;    // ���� ������ ������
                              s1_ob=0;

                              Memo1->Lines->Add("");
                              Memo1->Lines->Add( "\t �����: \t\t\t\t\t"+ FloatToStrF(s1_r,ffFixed,12,2) );
                               Memo1->Lines->Add("");
                              s1_all+=s1_r;    // ���� ���� ������
                              s1_r=0;

                 //����� ����� ����

              //  Memo1->Lines->Add(Query1->FieldByName("District")->AsString);
                  Memo1->Lines->Add( IntToStr(n)+ ". \t" + Query1->FieldByName("District")->AsString + " � ��� �����, ");
                  n++;


                f1=  Query1->FieldByName("District")->AsString;
                f2=  Query1->FieldByName("Object")->AsString;
                vidtr= Query1->FieldByName("Vidtr")->AsBoolean;



                             f3= Query1->FieldByName("Marka")->AsString;
                             f4= Query1->FieldByName("Govnumber")->AsString;
                             f5= Query1->FieldByName("Pricep")->AsString ;

                             chas=Query1->FieldByName("Ch")->AsFloat;
                             km=Query1->FieldByName("Km")->AsFloat;
                             //f8=Query1->FieldByName("Ch")->AsInteger;
                             //f9=Query1->FieldByName("Km")->AsInteger;
                             vid_izm=Query1->FieldByName("Vid_izm")->AsInteger;

                               if(vid_izm==1)
                              {
                               s1_m=  Query1->FieldByName("Cost1")->AsFloat;
                               s2_m=  Query1->FieldByName("Cost2")->AsFloat;
                              }
                              ch=Query1->FieldByName("Ch_v")->AsFloat;
                              cc=Query1->FieldByName("Za1_Chv")->AsFloat;


                               if(vid_izm==2)
                              {
                                sum_tkm=  Query1->FieldByName("Cost1")->AsFloat;   //��
                                col_tkm= Query1->FieldByName("Km")->AsFloat;
                              //  ed_tkm = Query1->FieldByName("Za1_km")->AsInteger;
                              }
                               if(vid_izm==3)
                                { sum_t= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_t= Query1->FieldByName("Km")->AsFloat;
                              //    ed_t = Query1->FieldByName("Za1_km")->AsInteger;
                                }
                                if(vid_izm==4)
                                { sum_mch= Query1->FieldByName("Cost1")->AsFloat;   //��
                                  col_mch= Query1->FieldByName("Km")->AsFloat;
                               //   ed_mch =  Query1->FieldByName("Za1_km")->AsInteger;
                                }


             }
              Query1->Next();
           }


              // ���� ���� ������� ������� ����
               {
                      /// ������ ���������� � ����������
                  //  n= printcar( n , vidtr , vid_izm, f1,f2,f3,f4, f5, f6, f7, cc, ch, km, chas, s1_m, s2_m,sum_mch,sum_tkm,sum_t,ed_mch,ed_t,ed_tkm,col_mch,col_t,col_tkm)   ;

                           //  s1_v+=s1_m + s2_m + cc*ch;    // ���� ������ ������
                          //   s1_m=s2_m=cc=ch=chas=km=0;

                             s1_v+=s1_m + s2_m + cc*ch + sum_tkm + sum_t + sum_mch;    // ���� ������ ������
                             s1_m=s2_m=cc=ch=chas=km=0;
                             sum_mch=sum_tkm=sum_t=col_mch=col_t=col_tkm=sv=0;

                              n=1;
                              s1_ob+=s1_v;    // ���� ��������� ������
                              s1_v=0;

                                  Memo1->Lines->Add("\t" + f2 + "\t\t\t\t\t "+ FloatToStrF(s1_ob,ffFixed,12,2) );
                             // Memo1->Lines->Add("");
                              s1_r+=s1_ob;    // ���� ������ ������
                              s1_ob=0;

                              Memo1->Lines->Add( "\t �����: \t\t\t\t\t "+ FloatToStrF(s1_r,ffFixed,12,2) );
                                Memo1->Lines->Add("");
                              s1_all+=s1_r;    // ���� ���� ������
                              s1_r=0;
               }



            Memo1->Lines->Add("");
            Memo1->Lines->Add("\t �����: \t\t\t\t\t " + FloatToStrF(s1_all,ffFixed,12,2));
            Memo1->Lines->Add("");

            Query1->Close();


}
//---------------------------------------------------------------------------






int printcar(int n,BOOL vidtr , int vid_izm, AnsiString f1,AnsiString f2, AnsiString f3,AnsiString f4,AnsiString f5,float f6,float f7,float cc,float ch,float km,float chas,float s1_m,float s2_m,float sum_mch,float sum_tkm,float sum_t,float ed_mch,float ed_t,float ed_tkm,float col_mch,float col_t,float col_tkm)
{

 /// ������ ���������� � ����������
                               if (f5=="")
                               {  if (vidtr==false)/// ���� ���������
                                  {
                                    if(s2_m!=0)
                                   {Form8->Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 +  "\t ��� " + " \t � \t" + FloatToStrF(f6,ffFixed,10,2) + "\t"  + FloatToStrF(chas, ffFixed, 10, 2) + "\t" +  FloatToStrF(s2_m,ffFixed,10,2));
                                   n++;


                                   Form8->Memo1->Lines->Add( "\t" + f4 + "\t ���  \t �� \t" + FloatToStrF(f7,ffFixed,10,2)+ "\t"   + FloatToStrF(km ,ffFixed,10,2) +  "\t" + FloatToStrF(s1_m,ffFixed,10,2));

                                    }
                                    if (sum_tkm!=0)
                                     {
                                     Form8->Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 +  "\t ��� " + " \t �/�� \t" + FloatToStrF(ed_tkm,ffFixed,10,2) + "\t"  + FloatToStrF(col_tkm,ffFixed,10,2) + "\t" +  FloatToStrF(sum_tkm,ffFixed,10,2));
                                     n++;
                                     }
                                    if (sum_t!=0)
                                     {
                                     Form8->Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 +  "\t ��� " + " \t � \t" + FloatToStrF(ed_t,ffFixed,10,2) + "\t"  + FloatToStrF(col_t,ffFixed,10,2) + "\t" +  FloatToStrF(sum_t,ffFixed,10,2));
                                     n++;
                                     }
                                      if (sum_mch!=0)
                                     {
                                     Form8->Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 +  "\t ��� " + " \t �/� \t" + FloatToStrF(ed_mch,ffFixed,10,2) + "\t"  + FloatToStrF(col_mch,ffFixed, 10, 2) + "\t" +  FloatToStrF(sum_mch,ffFixed,10,2));
                                     n++;
                                     }

                                  }
                                  else        // ���� ��������� ����� ��� ������
                                  {Form8->Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 + " "  "\t ��� " + " \t � \t" + FloatToStrF(f6,ffFixed,10,2) + "\t"  + FloatToStrF(chas, ffFixed, 10, 2) + "\t" +  FloatToStrF(s2_m,ffFixed,10,2));
                                    n++;
                                  }
                                }
                               else
                              {  if (s2_m!=0)

                               { Form8->Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 + " " + f4 + "\t ��� " + " \t � \t" + FloatToStrF(f6,ffFixed,10,2) + "\t"  + FloatToStrF(chas, ffFixed, 10, 2) + "\t" +  FloatToStrF(s2_m,ffFixed,10,2));
                                   n++;
                                Form8->Memo1->Lines->Add("\t c "+ f5 + "\t ���  \t �� \t" + FloatToStrF(f7,ffFixed,10,2)+ "\t"   + FloatToStrF(km,ffFixed, 10, 2) +  "\t" + FloatToStrF(s1_m,ffFixed,10,2));
                               }

                                 if (sum_tkm!=0)
                                     {
                                     Form8->Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 +  "\t ��� " + " \t �/�� \t" + FloatToStrF(ed_tkm,ffFixed,10,2) + "\t"  + FloatToStrF(col_tkm,ffFixed,10,2) + "\t" +  FloatToStrF(sum_tkm,ffFixed,10,2));
                                     n++;
                                     }
                                    if (sum_t!=0)
                                     {
                                     Form8->Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 +  "\t ��� " + " \t � \t" + FloatToStrF(ed_t,ffFixed,10,2) + "\t"  + FloatToStrF(col_t,ffFixed,10,2) + "\t" +  FloatToStrF(sum_t,ffFixed,10,2));
                                     n++;
                                     }
                                      if (sum_mch!=0)
                                     {
                                     Form8->Memo1->Lines->Add(IntToStr(n) +".\t �� ������ " + f3 +  "\t ��� " + " \t �/� \t" + FloatToStrF(ed_mch,ffFixed,10,2) + "\t"  + FloatToStrF(col_mch,ffFixed,10,2) + "\t" +  FloatToStrF(sum_mch,ffFixed,10,2));
                                     n++;
                                     }

                               }

                               if ((cc*ch)!=0)    // ����� ��� ����
                               {Form8->Memo1->Lines->Add(IntToStr(n) +".\t �/��. � ��� ���� \t ���  \t � \t" + FloatToStrF(cc,ffFixed,10,2) + "\t"  + FloatToStrF(ch,ffFixed,10,2) + "\t" +  FloatToStrF(cc*ch,ffFixed,10,2));
                                 n++;
                               }

   return n;
}





/************************************************************************************************************************/

void __fastcall TForm8::Button6Click(TObject *Sender)   //������ � excel
{
 // ������� �-�� �������*****************************************************************************************
 // ������� ������� ��� ������������ �������  �� ������ ����� +�����(2�������) + ������ ����� �� �������
  int blank=0;
  int i=0,j=0;

    blank++ ;
    i=2   ;
    ///������ ����� �������

    ShowMessage(Memo1->Lines->Count) ;
    while(i!=Memo1->Lines->Count )
     {
     i++;
      j++;
      if(j==89)
      { blank++;
        j=0;
      }
     }

     ShowMessage("����� �������: " + IntToStr(blank));

  // ������������� ���� � ����� �������
     AnsiString sFile;
     if (blank==1) sFile = ExtractFilePath(Application->ExeName)+"\\ACT2.xlt";
     else sFile = ExtractFilePath(Application->ExeName)+"\\ACT2_1.xlt";
     // �������������� Excel, ��������� ���� ������
     try {
       App=Variant::GetActiveObject("Excel.Application");
     } catch(...) {
     try { App=Variant::CreateObject("Excel.Application"); }
     catch (...) {
      Application->MessageBox("���������� ������� Microsoft Excel!"
      " �������� ����� ���������� �� ���������� �� �����������.","������",MB_OK+MB_ICONERROR);
        }}
     try {
      App.OlePropertyGet("WorkBooks").OleProcedure("Open",sFile.c_str(),0,false,1);
      Sh=App.OlePropertyGet("WorkSheets",1);
     } catch(...) {
      Application->MessageBox("������ �������� ������� Microsoft Excel!","������",MB_OK+MB_ICONERROR);
     }



//������� ������ ��� ����������**********************************************************************
      if (blank>1)
      {
       Variant v = App.OlePropertyGet("WorkSheets",1);

      //c��������� ������� "���� - ������ "
       Sh = Sh.OlePropertyGet("Range", "A160:G162");//�������
       Sh.OleProcedure("Select"); //
       Sh.OleProcedure("Copy");
      // �������� ������� ������
       v=v.OlePropertyGet("Cells", 1,9);
       v.OleProcedure("PasteSpecial");

       Sh=App.OlePropertyGet("WorkSheets",1);

       Sh = Sh.OlePropertyGet("Range", "A55:G108");//�������
       Sh.OleProcedure("Select"); //
       Sh.OleProcedure("Copy");
  //     blank=3;

        int k=55;
       for (; k<blank*55;k+=54)
       { v = App.OlePropertyGet("WorkSheets",1);
         v=v.OlePropertyGet("Cells", 54+k,1);
         v.OleProcedure("PasteSpecial");

       }

       // ��������� " ���� ������"
        Sh=App.OlePropertyGet("WorkSheets",1);
       Sh = Sh.OlePropertyGet("Range", "J1:P3");//�������
       Sh.OleProcedure("Select"); //
       Sh.OleProcedure("Copy");
        v = App.OlePropertyGet("WorkSheets",1);
        v=v.OlePropertyGet("Cells", 54+k-3,1);
        v.OleProcedure("PasteSpecial");
        Sh.OleProcedure("Delete");
        Sh=App.OlePropertyGet("WorkSheets",1);
      }
//��������� ��������� ������********************************************************************************************
    // App.OlePropertySet("Visible",true);


       j=0;
       blank=0;
       i=2;

    while(i!=Memo1->Lines->Count )
     {

      toExcelCell2(15+j+blank,1, Memo1->Lines->Strings[i])   ;

      i++;
      j++;
      if(j==40)
      j=43;
      if (j==91)
      {

          blank=blank+108;
                j=0;

      }

     }

     // ShowMessage("Exit") ;

  App.OlePropertySet("Visible",true);
  // ����������� �������
    Sh.Clear();
    App.Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::FormCreate(TObject *Sender)
{
Form8->MonthCalendar1->Date= Date() ;
Form8->MonthCalendar2->Date= Date() ;
}
//---------------------------------------------------------------------------


