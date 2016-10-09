//---------------------------------------------------------------------------

#include <vcl.h>





#pragma hdrstop
 #include "Unit6.h"
#include "Unit7.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;

//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm7::MonthCalendar1Click(TObject *Sender)
{
    Form7->Edit1->Text= DateToStr(MonthCalendar1->Date);
    Query1->Close();
         Query1->SQL->Clear();
         Query1->SQL->Add("select DISTINCT District from Districs");
         Query1->Open();
         Query1->First();
          Form7->ComboBox1->Items->Clear();
         while ( !Query1->Eof)
          {
                 Form7->ComboBox1->Items->Add(Query1->FieldByName("District")->AsString);
                 Query1->Next();
           }
          Form7->ComboBox1->ItemIndex=0;
    Form7->ComboBox1->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TForm7::ComboBox1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if(Key == VK_RETURN )
    {
    Query2->Close();
         Query2->SQL->Clear();

         //ShowMessage(Form7 ->ComboBox1->Text);
         Query2->SQL->Add("select DISTINCT Objects from Districs where district =:p1");
        Query2->ParamByName("p1")->AsString = Form7 ->ComboBox1->Text;
         Query2->Open();
         Query2->First();
          Form7->ComboBox2->Items->Clear();
         while ( !Query2->Eof)
          {
                 Form7->ComboBox2->Items->Add(Query2->FieldByName("Objects")->AsString);
                 Query2->Next();
           }
          Form7->ComboBox2->ItemIndex=0;

    Form7->ComboBox2->SetFocus();

    }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::ComboBox3KeyPress(TObject *Sender, char &Key)
{
      if(Key == VK_RETURN )

    {
        Query2->Close();
         Query2->SQL->Clear();


         Query2->SQL->Add("select DISTINCT Type from Cars where Vidtr =:p1");
         if (Form7 ->ComboBox3->Text== "Автотранспорт")
        {     ComboBox7->Visible=false;
               Label10->Visible=false;

               Form7->Edit6->Visible=true;
              Form7->Edit2->Visible=true;
             Form7->Edit4->Visible=true;
             Form7->Label8->Visible= true;

             CheckBox2->Enabled=true;
             CheckBox3->Enabled=true;
             CheckBox4->Enabled=true;

        Query2->ParamByName("p1")->AsBoolean=true;
         }
         if (Form7 ->ComboBox3->Text== "Механизмы")
         {     ComboBox7->Visible=true;
               Label10->Visible=true;
               Label10->Caption= "Жилье/Прочие";
              Form7->Edit2->Visible=false;
             Form7->Edit4->Visible=false;
             Form7->Label8->Visible=false;
             Form7->Edit6->Visible=false;

             CheckBox2->Enabled=false;
             CheckBox3->Enabled=false;
             CheckBox4->Enabled=false;


        Query2->ParamByName("p1")->AsBoolean=false;

            // Заполним Жилье/прочие combobox
                 Form7->ComboBox7->Items ->Clear();
                 Form7->ComboBox7->Items ->Add("Жилье");
                 Form7->ComboBox7->Items ->Add("Прочие");
                 Form7->ComboBox7->ItemIndex=0;

          }
         Query2->Open();
         Query2->First();
          Form7->ComboBox4->Items->Clear();
         while ( !Query2->Eof)
          {
                 Form7->ComboBox4->Items->Add(Query2->FieldByName("Type")->AsString);
                 Query2->Next();
           }
          Form7->ComboBox4->ItemIndex=0;




          Form7->ComboBox4->SetFocus();

      }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::ComboBox2KeyPress(TObject *Sender, char &Key)
{
        if(Key == VK_RETURN )
    {
          Form7->ComboBox3->SetFocus();

      }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::ComboBox4KeyPress(TObject *Sender, char &Key)
{
      if(Key == VK_RETURN )

    {
         Query2->Close();
         Query2->SQL->Clear();

        // ShowMessage(Form7 ->ComboBox3->Text);
         Query2->SQL->Add("select  DISTINCT Marka from Cars where Type =:p1");

        Query2->ParamByName("p1")->AsString=Form7 ->ComboBox4->Text;
         Query2->Open();
         Query2->First();
          Form7->ComboBox5->Items->Clear();
         while ( !Query2->Eof)
          {
                 Form7->ComboBox5->Items->Add(Query2->FieldByName("Marka")->AsString);
                 Query2->Next();
           }
          Form7->ComboBox5->ItemIndex=0;




          if(ComboBox4->Text=="Седельные тягачи")
          {
            ComboBox7->Visible=true;
            Label10->Visible=true;
            Label10->Caption="Прицеп";

           
          }
          else
          {   if (ComboBox3->Text=="Автотранспорт")
            { ComboBox7->Visible=false;
             Label10->Visible=false;
            }
          }


          Form7->ComboBox5->SetFocus();

      }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::ComboBox5KeyPress(TObject *Sender, char &Key)
{
    if(Key == VK_RETURN )

    {
         Query2->Close();
         Query2->SQL->Clear();

        // ShowMessage(Form7 ->ComboBox3->Text);
         Query2->SQL->Add("select  DISTINCT Govnumber from Cars where Marka =:p1");

        Query2->ParamByName("p1")->AsString=Form7 ->ComboBox5->Text;
         Query2->Open();
         Query2->First();
          Form7->ComboBox6->Items->Clear();
         while ( !Query2->Eof)
          {
                 Form7->ComboBox6->Items->Add(Query2->FieldByName("Govnumber")->AsString);
                 Query2->Next();
           }
          Form7->ComboBox6->ItemIndex=0;





          Form7->ComboBox6->SetFocus();

      }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Edit3KeyPress(TObject *Sender, char &Key)
{
      if(Key == VK_RETURN )

    {
           if (Form7->ComboBox3->Text=="Механизмы")
         {
          //ShowMessage("механизмы");
          // формируем форму заполнения для механизмов //



             //ShowMessage("Расчет цены для механизмов") ;

             Query2->Close();
             Query2->SQL->Clear();
             Query2->SQL->Add("select Za1Chas_other , Za1Chas from Cars where   Marka=:p2");


                  Query2->ParamByName("p2")->AsString=Form7 ->ComboBox5->Text;
                      Query2->Open();
                      if ( Form7->ComboBox7->Text == "Жилье")
                {Edit5->Text = FloatToStrF(Query2->FieldByName("Za1Chas")->AsFloat * StrToFloat(Form7->Edit3->Text),ffFixed,10,2);

                Edit7->Text= FloatToStr( Query2->FieldByName("Za1Chas")->AsFloat );
                 }
                       if ( Form7->ComboBox7->Text == "Прочие")
                { Edit5->Text = FloatToStrF(Query2->FieldByName("Za1Chas_other")->AsFloat * StrToFloat(Form7->Edit3->Text),ffFixed,10,2);
                  Edit7->Text= FloatToStr( Query2->FieldByName("Za1Chas_other")->AsFloat );
                 }
                        Query2->Close();

                        Form7->Button1->SetFocus();

           }

          else

        {  if (CheckBox2->Checked==true || CheckBox3->Checked==true || CheckBox4->Checked==true )
          Form7-> Edit6->SetFocus();
          else
          Form7->Edit2->SetFocus();

         }
      }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Edit2KeyPress(TObject *Sender, char &Key)
{

          float chas,km;// Для рассчета итоговой стоимости (edit4, edit5)


          if(Key == VK_RETURN )
      {
       if (Form7->ComboBox3->Text=="Автотранспорт")

          if (Form7->ComboBox4->Text=="Седельные тягачи")
          { // формируем форму заполнения для тягачей поля //
            //ShowMessage("Расчет цены для тягачей") ;

                Query2->Close();
                Query2->SQL->Clear();

                // ShowMessage(Form7 ->ComboBox3->Text);
                Query2->SQL->Add("select Za1km , Za1Km_5, Za1Km_10, Za1chas from Cars where (Govnumber =:p1) AND (Marka=:p2)");
                Query2->ParamByName("p1")->AsString=Form7 ->ComboBox6->Text;
                Query2->ParamByName("p2")->AsString=Form7 ->ComboBox5->Text;
                Query2->Open();

                if (ComboBox8->Text == "0%")
                        chas= Query2->FieldByName("Za1Km")->AsFloat * StrToFloat(Form7->Edit2->Text);
                if (ComboBox8->Text == "5%")
                        chas= Query2->FieldByName("Za1Km_5")->AsFloat * StrToFloat(Form7->Edit2->Text);
                if (ComboBox8->Text == "10%")
                        chas= Query2->FieldByName("Za1Km_10")->AsFloat * StrToFloat(Form7->Edit2->Text);

                km= Query2->FieldByName("Za1Chas")->AsFloat * StrToFloat(Form7->Edit3->Text);

                if (ComboBox8->Text == "0%")
                        Edit6->Text=FloatToStrF(Query2->FieldByName("Za1Km")->AsFloat,ffFixed,10,2);
                if (ComboBox8->Text == "5%")
                        Edit6->Text=FloatToStrF(Query2->FieldByName("Za1Km_5")->AsFloat,ffFixed,10,2 );
                if (ComboBox8->Text == "10%")
                        Edit6->Text=FloatToStrF(Query2->FieldByName("Za1Km_10")->AsFloat,ffFixed,10,2);
                Edit7->Text= FloatToStrF( Query2->FieldByName("Za1Chas")->AsFloat,ffFixed,10,2 );


                Query2->Close();

               if(ComboBox7->Text !="Нет")
               {
                 Query2->SQL->Clear();
                 Query2->SQL->Add("select Za1km , Za1Km_5, Za1Km_10, Za1chas from Cars where Marka =:p1");
                 Query2->ParamByName("p1")->AsString=Form7 ->ComboBox7->Text;
                 Query2->Open();


                 if (ComboBox8->Text == "0%")
                       chas= chas+Query2->FieldByName("Za1Km")->AsFloat * StrToFloat(Form7->Edit2->Text);
                 if (ComboBox8->Text == "5%")
                       chas= chas+Query2->FieldByName("Za1Km_5")->AsFloat * StrToFloat(Form7->Edit2->Text);
                 if (ComboBox8->Text == "10%")
                       chas= chas+Query2->FieldByName("Za1Km_10")->AsFloat * StrToFloat(Form7->Edit2->Text);

                 km=  km +  Query2->FieldByName("Za1Chas")->AsFloat * StrToFloat(Form7->Edit3->Text);

                 if (ComboBox8->Text == "0%")
                         Edit6->Text=FloatToStr(StrToFloat(Edit6->Text)+ Query2->FieldByName("Za1Km")->AsFloat );
                 if (ComboBox8->Text == "5%")
                         Edit6->Text=FloatToStr(StrToFloat(Edit6->Text)+ Query2->FieldByName("Za1Km_5")->AsFloat );
                 if (ComboBox8->Text == "10%")
                         Edit6->Text=FloatToStr(StrToFloat(Edit6->Text)+ Query2->FieldByName("Za1Km_10")->AsFloat );

                         Edit7->Text= FloatToStr(StrToFloat(Edit7->Text)+ Query2->FieldByName("Za1Chas")->AsFloat );


             }
              Edit4->Text=FloatToStrF( chas,ffFixed,10,2 );
              Edit5->Text= FloatToStrF(  km,ffFixed,10,2 );
              Form7->Button1->SetFocus();


          }
           else
           { // остальной автотранспорт
            //    ShowMessage("Расчет цены");

                Query2->Close();
                Query2->SQL->Clear();

                // ShowMessage(Form7 ->ComboBox3->Text);
                Query2->SQL->Add("select Za1km , Za1Km_5, Za1Km_10, Za1MChas, Za1chas from Cars where (Govnumber =:p1) AND (Marka=:p2)");

                 Query2->ParamByName("p1")->AsString=Form7 ->ComboBox6->Text;
                 Query2->ParamByName("p2")->AsString=Form7 ->ComboBox5->Text;
                      Query2->Open();
                if(CheckBox4->Checked==true)
                {
                  Edit4->Text= FloatToStrF(Query2->FieldByName("Za1MChas")->AsFloat * StrToFloat(Form7->Edit2->Text),ffFixed,10,2);
                  Edit6->Text=FloatToStr(Query2->FieldByName("Za1MChas")->AsFloat );
                 }
                 else
              {

                if (ComboBox8->Text == "0%")
                Edit4->Text= FloatToStrF(Query2->FieldByName("Za1Km")->AsFloat * StrToFloat(Form7->Edit2->Text),ffFixed,10,2);
                if (ComboBox8->Text == "5%")
                Edit4->Text= FloatToStrF(Query2->FieldByName("Za1Km_5")->AsFloat * StrToFloat(Form7->Edit2->Text),ffFixed,10,2);
                if (ComboBox8->Text == "10%")
                Edit4->Text= FloatToStrF(Query2->FieldByName("Za1Km_10")->AsFloat * StrToFloat(Form7->Edit2->Text),ffFixed,10,2);

                Edit5->Text= FloatToStrF(Query2->FieldByName("Za1Chas")->AsFloat * StrToFloat(Form7->Edit3->Text),ffFixed,10,2);


                 if (ComboBox8->Text == "0%")
                Edit6->Text=FloatToStr(Query2->FieldByName("Za1Km")->AsFloat );
                  if (ComboBox8->Text == "5%")
                 Edit6->Text=FloatToStr(Query2->FieldByName("Za1Km_5")->AsFloat );
                  if (ComboBox8->Text == "10%")
                  Edit6->Text=FloatToStr(Query2->FieldByName("Za1Km_10")->AsFloat );

                Edit7->Text= FloatToStr( Query2->FieldByName("Za1Chas")->AsFloat );
               }
                Form7->Button1->SetFocus();

                //Form7->Visible=false;
            }

     }


}


//---------------------------------------------------------------------------
void __fastcall TForm7::ComboBox6KeyPress(TObject *Sender, char &Key)
{
        if(Key == VK_RETURN )

    {     if ( ComboBox3->Text== "Механизмы" )
         ComboBox7->SetFocus();
         else
         {   if(ComboBox4->Text=="Седельные тягачи")
           {     if(ComboBox4->Text=="Седельные тягачи")
          {
            ComboBox7->Visible=true;
            Label10->Visible=true;
            Label10->Caption="Прицеп";

            // заполним прицепы
             Query2->Close();
                 Query2->SQL->Clear();

                // ShowMessage(Form7 ->ComboBox3->Text);
            Query2->SQL->Add("select Pricep from Cars where Govnumber =:p1");

                 Query2->ParamByName("p1")->AsString=Form7 ->ComboBox6->Text;
                 Query2->Open();
                 // ShowMessage(Query2->FieldByName("Pricep")->AsString);
                 Form7->ComboBox7->Items ->Clear();

                 Form7->ComboBox7->Items ->Add("Нет");
              AnsiString pricep =  Query2->FieldByName("Pricep")->AsString;


              AnsiString pr="";
                  char * pricep2 = pricep.c_str();
                  int j=0;
              //   ShowMessage(AnsiString(pricep2));
              for (int i =0 ; i < pricep.Length(); i ++)
               {  if (pricep2[i] != ' ')
                // {ShowMessage("Пробел");
                 pr=pr+  pricep2[i];

              else //if(pr ==  ' ')
                   {
                      Form7->ComboBox7->Items ->Add(pr);
                     j++;
                      pr="";
                   }
                 if (i==pricep.Length()-1)
                Form7->ComboBox7->Items ->Add(pr);
               }

                  Form7->ComboBox7->ItemIndex=0;

          }
                ComboBox7->SetFocus();
            }
          else
              if (CheckBox2->Checked==true || CheckBox3->Checked==true || CheckBox4->Checked==true )
          Form7-> Edit2->SetFocus();
          else
           Form7->Edit3->SetFocus();
           
         }
      }
      if (ComboBox7->Visible == false)
                ComboBox8->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ComboBox7KeyPress(TObject *Sender, char &Key)
{
       if(Key == VK_RETURN )

             Form7->ComboBox8->SetFocus();


}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button1Click(TObject *Sender)
{
           // проверка соответсвия цены






     if (Form7->ComboBox3->Text=="Автотранспорт")

          if (Form7->ComboBox4->Text=="Седельные тягачи")
          {  //   Добавляем тягачи
             // ShowMessage("Добавляем тягачи!!!");
               Form7->Query3->Close();
              // Form7->Query3->RequestLive=true;
               Form7->Query3->Open();

                Form7->Query3->First();            // перебираем все элементы и проверяем есть такие
                  while ( !Form7->Query3->Eof)
                   {

                          if  (Form7->Query3->FieldByName("Date2") ->AsString == Form7->Edit1->Text && Form7->Query3->FieldByName("Type") ->AsString == Form7->ComboBox4->Text && Form7->Query3->FieldByName("Object") ->AsString == Form7->ComboBox2->Text && Form7->Query3->FieldByName("Marka") ->AsString == Form7->ComboBox5->Text      && Form7->Query3->FieldByName("Govnumber") ->AsString == Form7->ComboBox6->Text && Form7->Query3->FieldByName("Km")->AsFloat == StrToFloat ( Form7->Edit2->Text)    && Form7->Query3->FieldByName("Ch")->AsFloat == StrToFloat ( Form7->Edit3->Text))
                            {
                               ShowMessage("Объект с таким именем существует !!!") ;

                                   return;
                                     }
                                 Form7->Query3->Next();
                  }

                  ///проверка на соответсвие цены
             //___________________________________________________________________
                  Query4->Close();
                  Query4->SQL->Clear();
                  Query4->SQL->Add("select * from Cars where Marka=:p1 AND Govnumber=:p2");
                  Query4->ParamByName("p1")->AsString=ComboBox5->Text;
                  Query4->ParamByName("p2")->AsString=ComboBox6->Text;

                  Query4->Open();

                  if ( Query4->FieldByName("Za1Chas")->AsString!=Edit7->Text ||   Query4->FieldByName("Za1Km")->AsString!=Edit6->Text  )

                   {
                      if (ComboBox8->Text=="0%")
                     {
                      int buttonSelected=MessageDlg("Цена за 1 км или за 1 час не соответствует данным в Машинах, все равно продолжить???",mtConfirmation	, mbOKCancel, 0);
                   // Показ типа выбранной кнопки
                         if (buttonSelected == 1 )
                       {   // ShowMessage("Загружаем!!!!");

                         }
                        if (buttonSelected == 2)
                         {
                          ShowMessage("Отменено!");
                          return;
                          }
                     }
                   }

                  Query4->Close();
      //_________________________________________________________________________________
    /// если проверки пройдена добавляем объект



   Form7-> Query3->Close();


   Form7-> Query3->RequestLive=true;
   Form7->  Query3->Open();
        if(! Form7->Query3->Prepared)
            Form7->Query3->Prepare();




        Form7->Query3->Insert();

        Form7->Query3->FieldByName("Date2")->AsString=  Form7->Edit1->Text;
        Form7->Query3->FieldByName("Vidtr")->AsBoolean= false;
        Form7->Query3->FieldByName("District")->AsString=  Form7->ComboBox1->Text;
        Form7->Query3->FieldByName("Object")->AsString=  Form7->ComboBox2->Text;
        Form7->Query3->FieldByName("Type")->AsString=  Form7->ComboBox4->Text;
        Form7->Query3->FieldByName("Marka")->AsString = Form7->ComboBox5->Text;
        Form7->Query3->FieldByName("Govnumber")->AsString = Form7->ComboBox6->Text;
         if(ComboBox7->Text !="Нет")
        Form7->Query3->FieldByName("Pricep")->AsString = Form7->ComboBox7->Text;


        if (CheckBox2->Checked==true || CheckBox3->Checked==true || CheckBox4->Checked==true )  // если т т/км м/ч
        {
        Form7->Query3->FieldByName("Km")->AsFloat = StrToFloat(Form7->Edit2->Text);
      //  Form7->Query3->FieldByName("Ch")->AsInteger =  StrToInt(Form7->Edit3->Text);
        Form7->Query3->FieldByName("Cost1")->AsFloat = StrToFloat(Form7->Edit4->Text);
      //  Form7->Query3->FieldByName("Cost2")->AsInteger =  StrToInt(Form7->Edit5->Text);
        Form7->Query3->FieldByName("Za1_km")->AsFloat = StrToFloat(Form7->Edit6->Text);
        //Form7->Query3->FieldByName("Za1_ch")->AsInteger =  StrToInt(Form7->Edit7->Text);



          if(CheckBox2->Checked==true)
          Form7->Query3->FieldByName("Vid_izm")->AsInteger = 2;
          if(CheckBox3->Checked==true)
          Form7->Query3->FieldByName("Vid_izm")->AsInteger = 3;
          if(CheckBox4->Checked==true)
          Form7->Query3->FieldByName("Vid_izm")->AsInteger = 4;

         }
         else

         {
          Form7->Query3->FieldByName("Km")->AsFloat = StrToFloat(Form7->Edit2->Text);
          Form7->Query3->FieldByName("Ch")->AsFloat =  StrToFloat(Form7->Edit3->Text);
          Form7->Query3->FieldByName("Cost1")->AsFloat = StrToFloat(Form7->Edit4->Text);
          Form7->Query3->FieldByName("Cost2")->AsFloat =  StrToFloat(Form7->Edit5->Text);
          Form7->Query3->FieldByName("Za1_km")->AsFloat = StrToFloat(Form7->Edit6->Text);
          Form7->Query3->FieldByName("Za1_ch")->AsFloat =  StrToFloat(Form7->Edit7->Text);
         }

          if (Form7->CheckBox1->Checked==true)
         { Form7->Query3->FieldByName("Ch_v")->AsFloat = StrToFloat(Form7->Edit8->Text);
           Form7->Query3->FieldByName("Za1_chv")->AsFloat =  StrToFloat(Form7->Edit9->Text);
         }

         Form7->Query3->Post();



          }
           else
           { //   Добавляем автотранспорт
             // ShowMessage("Добавляем автотранспорт!!!");


                Form7->Query3->Close();
              // Form7->Query3->RequestLive=true;
               Form7->Query3->Open();

                Form7->Query3->First();            // перебираем все элементы и проверяем есть такие
   while ( !Form7->Query3->Eof)
      {

        if  (Form7->Query3->FieldByName("Date2") ->AsString == Form7->Edit1->Text && Form7->Query3->FieldByName("Type") ->AsString == Form7->ComboBox4->Text && Form7->Query3->FieldByName("Object") ->AsString == Form7->ComboBox2->Text && Form7->Query3->FieldByName("Marka") ->AsString == Form7->ComboBox5->Text      && Form7->Query3->FieldByName("Govnumber") ->AsString == Form7->ComboBox6->Text && Form7->Query3->FieldByName("Km")->AsFloat == StrToFloat ( Form7->Edit2->Text)    && Form7->Query3->FieldByName("Ch")->AsFloat == StrToFloat ( Form7->Edit3->Text))
       {
       ShowMessage("Объект с таким именем существует !!!") ;

        return;
        }
         Form7->Query3->Next();
      }
            ///проверка на соответсвие цены
             //___________________________________________________________________
                  Query4->Close();
                  Query4->SQL->Clear();
                  Query4->SQL->Add("select * from Cars where Marka=:p1 AND Govnumber=:p2");
                  Query4->ParamByName("p1")->AsString=ComboBox5->Text;
                  Query4->ParamByName("p2")->AsString=ComboBox6->Text;

                  Query4->Open();

                  if ( Query4->FieldByName("Za1Chas")->AsString!=Edit7->Text ||   Query4->FieldByName("Za1Km")->AsString!=Edit6->Text)

                   {
                      if (ComboBox8->Text=="0%")
                     {
                      int buttonSelected=MessageDlg("Цена за 1 км или за 1 час не соответствует данным в Машинах, все равно продолжить???",mtConfirmation	, mbOKCancel, 0);
                   // Показ типа выбранной кнопки
                         if (buttonSelected == 1 )
                       {   // ShowMessage("Загружаем!!!!");

                         }
                        if (buttonSelected == 2)
                         {
                          ShowMessage("Отменено!");
                          return;
                          }
                      }
                   }

                  Query4->Close();
      //_________________________________________________________________________________

    /// если проверка пройдена добавляем объект
   Form7-> Query3->Close();


   Form7-> Query3->RequestLive=true;
   Form7->  Query3->Open();
        if(! Form7->Query3->Prepared)
            Form7->Query3->Prepare();




        Form7->Query3->Insert();

        Form7->Query3->FieldByName("Date2")->AsString=  Form7->Edit1->Text;
        Form7->Query3->FieldByName("Vidtr")->AsBoolean= false;
        Form7->Query3->FieldByName("District")->AsString=  Form7->ComboBox1->Text;
        Form7->Query3->FieldByName("Object")->AsString=  Form7->ComboBox2->Text;
        Form7->Query3->FieldByName("Type")->AsString=  Form7->ComboBox4->Text;
        Form7->Query3->FieldByName("Marka")->AsString = Form7->ComboBox5->Text;
        Form7->Query3->FieldByName("Govnumber")->AsString = Form7->ComboBox6->Text;


         if (CheckBox2->Checked==true || CheckBox3->Checked==true || CheckBox4->Checked==true )  // если т т/км м/ч
        {

        Form7->Query3->FieldByName("Km")->AsFloat = StrToFloat(Form7->Edit2->Text);
        //Form7->Query3->FieldByName("Ch")->AsInteger =  StrToInt(Form7->Edit3->Text);
        Form7->Query3->FieldByName("Cost1")->AsFloat = StrToFloat(Form7->Edit4->Text);
        //Form7->Query3->FieldByName("Cost2")->AsInteger =  StrToInt(Form7->Edit5->Text);


        Form7->Query3->FieldByName("Za1_km")->AsFloat = StrToFloat(Form7->Edit6->Text);
       // Form7->Query3->FieldByName("Za1_ch")->AsInteger =  StrToInt(Form7->Edit7->Text);

           if(CheckBox2->Checked==true)
          Form7->Query3->FieldByName("Vid_izm")->AsInteger = 2;
          if(CheckBox3->Checked==true)
          Form7->Query3->FieldByName("Vid_izm")->AsInteger = 3;
          if(CheckBox4->Checked==true)
          Form7->Query3->FieldByName("Vid_izm")->AsInteger = 4;


         }
         else
         {
                Form7->Query3->FieldByName("Km")->AsFloat = StrToFloat(Form7->Edit2->Text);
                Form7->Query3->FieldByName("Ch")->AsFloat =  StrToFloat(Form7->Edit3->Text);
                Form7->Query3->FieldByName("Cost1")->AsFloat = StrToFloat(Form7->Edit4->Text);
                Form7->Query3->FieldByName("Cost2")->AsFloat =  StrToFloat(Form7->Edit5->Text);
                Form7->Query3->FieldByName("Za1_km")->AsFloat = StrToFloat(Form7->Edit6->Text);
                Form7->Query3->FieldByName("Za1_ch")->AsFloat =  StrToFloat(Form7->Edit7->Text);


         }
          if (Form7->CheckBox1->Checked==true)
         { Form7->Query3->FieldByName("Ch_v")->AsFloat = StrToFloat(Form7->Edit8->Text);
           Form7->Query3->FieldByName("Za1_chv")->AsFloat =  StrToFloat(Form7->Edit9->Text);
         }
        Form7->Query3->Post();




            }




          if (Form7->ComboBox3->Text=="Механизмы")
         {
                 //   Добавляем механизмы
            //  ShowMessage("Добавляем механизмы!!!");

             Form7->Query3->Close();
              // Form7->Query3->RequestLive=true;
               Form7->Query3->Open();

                Form7->Query3->First();            // перебираем все элементы и проверяем есть такие
   while ( !Form7->Query3->Eof)
      {

        if  (Form7->Query3->FieldByName("Date2") ->AsString == Form7->Edit1->Text && Form7->Query3->FieldByName("Type") ->AsString == Form7->ComboBox4->Text && Form7->Query3->FieldByName("Object") ->AsString == Form7->ComboBox2->Text && Form7->Query3->FieldByName("Marka") ->AsString == Form7->ComboBox5->Text      && Form7->Query3->FieldByName("Govnumber") ->AsString == Form7->ComboBox6->Text && Form7->Query3->FieldByName("Km")->AsFloat == StrToFloat ( Form7->Edit2->Text)    && Form7->Query3->FieldByName("Ch")->AsFloat == StrToFloat ( Form7->Edit3->Text))
       {
       ShowMessage("Объект с таким именем существует !!!") ;

        return;
        }
         Form7->Query3->Next();
      }

            ///проверка на соответсвие цены
             //___________________________________________________________________
                  Query4->Close();
                  Query4->SQL->Clear();
                  Query4->SQL->Add("select * from Cars where Marka=:p1 AND Govnumber=:p2");
                  Query4->ParamByName("p1")->AsString=ComboBox5->Text;
                  Query4->ParamByName("p2")->AsString=ComboBox6->Text;

                  Query4->Open();

                  if ( Query4->FieldByName("Za1Chas")->AsString!=Edit7->Text )

                   {
                      if (ComboBox8->Text=="0%")
                     {
                      int buttonSelected=MessageDlg("Цена за 1 км или за 1 час не соответствует данным в Машинах, все равно продолжить???",mtConfirmation	, mbOKCancel, 0);
                   // Показ типа выбранной кнопки
                         if (buttonSelected == 1 )
                       {   // ShowMessage("Загружаем!!!!");

                         }
                        if (buttonSelected == 2)
                         {
                          ShowMessage("Отменено!");
                          return;
                          }
                      }
                   }

                  Query4->Close();
      //_________________________________________________________________________________

    /// если проверка пройдена добавляем объект
   Form7-> Query3->Close();


   Form7-> Query3->RequestLive=true;
   Form7->  Query3->Open();
        if(! Form7->Query3->Prepared)
            Form7->Query3->Prepare();




        Form7->Query3->Insert();

        Form7->Query3->FieldByName("Date2")->AsString=  Form7->Edit1->Text;
        Form7->Query3->FieldByName("Vidtr")->AsBoolean= true;
        Form7->Query3->FieldByName("District")->AsString=  Form7->ComboBox1->Text;
        Form7->Query3->FieldByName("Object")->AsString=  Form7->ComboBox2->Text;
        Form7->Query3->FieldByName("Type")->AsString=  Form7->ComboBox4->Text;
        Form7->Query3->FieldByName("Marka")->AsString = Form7->ComboBox5->Text;
        Form7->Query3->FieldByName("Govnumber")->AsString = Form7->ComboBox6->Text;
      //  Form7->Query3->FieldByName("Km")->AsInteger = StrToInt(Form7->Edit2->Text);
        Form7->Query3->FieldByName("Ch")->AsFloat =  StrToFloat(Form7->Edit3->Text);
     //   Form7->Query3->FieldByName("Pricep")->AsString = Form7->ComboBox7->Text;
        if (ComboBox7->Text=="Жилье")
         Form7->Query3->FieldByName("Zh")->AsBoolean= true;
        if (ComboBox7->Text=="Прочие")
          Form7->Query3->FieldByName("Zh")->AsBoolean= false;
          Form7->Query3->FieldByName("Cost2")->AsFloat = StrToFloat(Form7->Edit5->Text);
         // Form7->Query3->FieldByName("Za1_km")->AsInteger = StrToInt(Form7->Edit6->Text);
        Form7->Query3->FieldByName("Za1_ch")->AsFloat =  StrToFloat(Form7->Edit7->Text);
          if (Form7->CheckBox1->Checked==true)
         { Form7->Query3->FieldByName("Ch_v")->AsFloat = StrToFloat(Form7->Edit8->Text);
           Form7->Query3->FieldByName("Za1_chv")->AsFloat =  StrToFloat(Form7->Edit9->Text);
         }
        Form7->Query3->Post();



           }
      Form7->Visible=false;
      Form6->Query1->Close();
      Form6->Query1->Open();
}
//---------------------------------------------------------------------------





void __fastcall TForm7::CheckBox1Click(TObject *Sender)
{
   if (Form7->CheckBox1->Checked==true)

    {

       Form7->Label14->Visible=true;
       Form7->Label15->Visible=true;
       Form7->Edit8->Visible=true;
       Form7->Edit9->Visible=true;
       Edit10->Visible=true;
       Edit8->SetFocus();

    }
   else
    {  Form7->Label14->Visible=false;
       Form7->Label15->Visible=false;
       Form7->Edit8->Visible=false;
       Form7->Edit9->Visible=false;
       Form7->Edit10->Visible=false ;

    }

}
//---------------------------------------------------------------------------



void __fastcall TForm7::Button2Click(TObject *Sender)
{
   /*       if(Edit1->Text == "" || ComboBox1->Text == "" || ComboBox2->Text == "" ||ComboBox4->Text == "" || ComboBox5->Text == ""  )
          {
            ShowMessage("Вы не заполнили все поля ");
            return;
          }

         if( ComboBox4->Text == "Седельные тягачи" )
         { //ShowMessage("Расчет цены для тягачей") ;

                Query2->Close();
                 Query2->SQL->Clear();

                // ShowMessage(Form7 ->ComboBox3->Text);
            Query2->SQL->Add("select Za1km , Za1chas from Cars where (Govnumber =:p1) AND (Marka=:p2)");

                 Query2->ParamByName("p1")->AsString=Form7 ->ComboBox6->Text;
                  Query2->ParamByName("p2")->AsString=Form7 ->ComboBox5->Text;
                      Query2->Open();
                int chas= int(Query2->FieldByName("Za1Km")->AsInteger * StrToFloat(Form7->Edit2->Text));
                 int km= int(Query2->FieldByName("Za1Chas")->AsInteger * StrToFloat(Form7->Edit3->Text));

                 Edit6->Text=IntToStr(Query2->FieldByName("Za1Km")->AsInteger );
                Edit7->Text= IntToStr( Query2->FieldByName("Za1Chas")->AsInteger );


                       Query2->Close();

               if(ComboBox7->Text !="Нет")
           { Query2->SQL->Clear();

                // ShowMessage(Form7 ->ComboBox3->Text);
            Query2->SQL->Add("select Za1km , Za1chas from Cars where Marka =:p1");

                 Query2->ParamByName("p1")->AsString=Form7 ->ComboBox7->Text;

                      Query2->Open();
                       chas= chas+int(Query2->FieldByName("Za1Km")->AsInteger * StrToFloat(Form7->Edit2->Text));
                       km=  km+  int(Query2->FieldByName("Za1Chas")->AsInteger * StrToFloat(Form7->Edit3->Text));
                         Edit6->Text=IntToStr(StrToInt(Edit6->Text)+ Query2->FieldByName("Za1Km")->AsInteger );
                        Edit7->Text= IntToStr(StrToInt(Edit7->Text)+ Query2->FieldByName("Za1Chas")->AsInteger );


             }
              Edit4->Text=IntToStr( chas );
                Edit5->Text= IntToStr(  km );


            }
            else
            { if (ComboBox3->Text == "Автотранспорт")
                Query2->SQL->Clear();

                // ShowMessage(Form7 ->ComboBox3->Text);
            Query2->SQL->Add("select Za1km , Za1chas from Cars where Marka =:p1");

                 Query2->ParamByName("p1")->AsString=Form7 ->ComboBox7->Text;

                      Query2->Open();
                   int    chas= chas+int(Query2->FieldByName("Za1Km")->AsInteger * StrToFloat(Form7->Edit2->Text));
                    int   km=  km+  int(Query2->FieldByName("Za1Chas")->AsInteger * StrToFloat(Form7->Edit3->Text));
                         Edit6->Text=IntToStr(StrToInt(Edit6->Text)+ Query2->FieldByName("Za1Km")->AsInteger );
                        Edit7->Text= IntToStr(StrToInt(Edit7->Text)+ Query2->FieldByName("Za1Chas")->AsInteger );



              Edit4->Text=IntToStr( chas );
                Edit5->Text= IntToStr(  km );
            }

           if( ComboBox3->Text == "Механизмы" )
           { //ShowMessage("Расчет цены для механизмов") ;

             Query2->Close();
             Query2->SQL->Clear();
             Query2->SQL->Add("select Za1Chas_other , Za1Chas from Cars where   Marka=:p2");


                  Query2->ParamByName("p2")->AsString=Form7 ->ComboBox5->Text;
                      Query2->Open();
                      if ( Form7->ComboBox7->Text == "Жилье")
                {Edit5->Text = IntToStr(int(Query2->FieldByName("Za1Chas")->AsInteger * StrToFloat(Form7->Edit3->Text)));

                Edit7->Text= IntToStr( Query2->FieldByName("Za1Chas")->AsInteger );
                 }
                       if ( Form7->ComboBox7->Text == "Прочие")
                { Edit5->Text = IntToStr(int(Query2->FieldByName("Za1Chas_other")->AsInteger * StrToFloat(Form7->Edit3->Text)));
                  Edit7->Text= IntToStr( Query2->FieldByName("Za1Chas_other")->AsInteger );
                 }
                   Edit6->Text= IntToStr( 0 );
                       Query2->Close();

           }

           Form7->Button1->SetFocus();   */
}
//---------------------------------------------------------------------------



void __fastcall TForm7::CheckBox2Click(TObject *Sender)
{
   if (Form7->CheckBox2->Checked==true)
    {
    CheckBox3->Checked=false;
    CheckBox4->Checked=false;
    Label8->Caption="Кол-во";
    Label12->Caption="Тариф за 1 т/км";
    Label9->Visible=false;
    Edit3->Visible=false;
    Edit5->Visible=false;
    Edit7->Visible=false;
    Edit2->SetFocus();
    Edit6->Clear();
    Edit4->Clear();
    }
   else
    {
    Label8->Caption="Пробег";
    Label12->Caption="Тарифы за 1 км, за 1 час";
    Label9->Visible=true;
    Edit3->Visible=true;
    Edit5->Visible=true;
    Edit7->Visible=true;
    Edit4->Clear();
    Edit5->Clear();
    Edit6->Clear();
    Edit7->Clear();
    Edit2->SetFocus();

    }

}
//---------------------------------------------------------------------------

void __fastcall TForm7::CheckBox3Click(TObject *Sender)
{  if (Form7->CheckBox3->Checked==true)
    {

  CheckBox2->Checked=false;
  CheckBox4->Checked=false;
   Label8->Caption="Кол-во";
    Label12->Caption="Тариф за 1 тонну";
    Label9->Visible=false;
    Edit3->Visible=false;
    Edit5->Visible=false;
    Edit7->Visible=false;
    Edit2->SetFocus();
    Edit6->Clear();
    Edit4->Clear();
    }
    else
    {
        Label8->Caption="Пробег";
    Label12->Caption="Тарифы за 1 км, за 1 час";
    Label9->Visible=true;
    Edit3->Visible=true;
    Edit5->Visible=true;
    Edit7->Visible=true;

    Edit4->Clear();
    Edit5->Clear();
    Edit6->Clear();
    Edit7->Clear();
    Edit2->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm7::CheckBox4Click(TObject *Sender)
{
  if (Form7->CheckBox4->Checked==true)
  {
 CheckBox3->Checked=false;
 CheckBox2->Checked=false;
   Label8->Caption="Кол-во";
    Label12->Caption="Тариф за 1 м/ч";
    Label9->Visible=false;
    Edit3->Visible=false;
    Edit5->Visible=false;
    Edit7->Visible=false;
    Edit2->SetFocus();
    Edit6->Clear();
    Edit4->Clear();
 }
 else
 {
    Label8->Caption="Пробег";
    Label12->Caption="Тарифы за 1 км, за 1 час";
    Label9->Visible=true;
    Edit3->Visible=true;
    Edit5->Visible=true;
    Edit7->Visible=true;

    Edit4->Clear();
    Edit5->Clear();
    Edit6->Clear();
    Edit7->Clear();
    Edit2->SetFocus();

 }
}
//---------------------------------------------------------------------------


void __fastcall TForm7::Edit6KeyPress(TObject *Sender, char &Key)
{
    if(Key == VK_RETURN )

    {


          if (CheckBox2->Checked==true || CheckBox3->Checked==true || CheckBox4->Checked==true )
          {
            Form7-> Edit4->Text=FloatToStrF(StrToFloat(Edit2->Text)*StrToFloat(Edit6->Text),ffFixed,10,2) ;
           Button1->SetFocus();

           }
           else
           {
             Form7-> Edit4->Text=FloatToStrF(StrToFloat(Edit2->Text)*StrToFloat(Edit6->Text),ffFixed,10,2) ;
             Button1->SetFocus();

           }

      }
}
//---------------------------------------------------------------------------



void __fastcall TForm7::Edit7KeyPress(TObject *Sender, char &Key)
{   if(Key == VK_RETURN )

    {
    Form7-> Edit5->Text=FloatToStrF(StrToFloat(Edit3->Text)*StrToFloat(Edit7->Text),ffFixed,10,2) ;
             Button1->SetFocus();
             }
}
//---------------------------------------------------------------------------







void __fastcall TForm7::Edit8KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if(Key == VK_RETURN )

    {

             Edit9->SetFocus();
             }
}
//---------------------------------------------------------------------------


void __fastcall TForm7::Edit9KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if(Key == VK_RETURN )
      {
       Edit10->Text=FloatToStrF(StrToFloat(Edit8->Text)*StrToFloat(Edit9->Text),ffFixed,10,2);
        Button1->SetFocus();
       }
}
//---------------------------------------------------------------------------


void __fastcall TForm7::FormCreate(TObject *Sender)
{
Form7->MonthCalendar1->Date= Date() ;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ComboBox8KeyPress(TObject *Sender, char &Key)
{
       if(Key == VK_RETURN )

    {
       if ( ComboBox8->Text=="5%" || ComboBox8->Text=="0%"  || ComboBox8->Text=="10%")

       {

       if (CheckBox2->Checked==true || CheckBox3->Checked==true || CheckBox4->Checked==true )
          Form7-> Edit2->SetFocus();
          else
           Form7->Edit3->SetFocus();
       }
       else
       {
       ShowMessage("Выбирите одно из значений!!!");
          ComboBox8->SetFocus();
       }
    }
}
//---------------------------------------------------------------------------



