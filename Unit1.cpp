//---------------------------------------------------------------------------

#include <vcl.h>
#include <FileCtrl.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit6.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 if(!Session->IsAlias("autopark2"))
{
//InitialisePatchDB() - это твоя функция которая возвращает путь к папке бд
String Patch = ExtractFilePath(Application->ExeName)+ "BD\\";                   
Session->AddStandardAlias("autopark2",Patch  ,"PARADOX")   ;
Session->SaveConfigFile();
}
 else
 {
 Session->DeleteAlias("autopark2") ;
 String Patch = ExtractFilePath(Application->ExeName)+ "BD\\";
Session->AddStandardAlias("autopark2",Patch  ,"PARADOX")   ;
        Session->SaveConfigFile();
 }
}
//---------------------------------------------------------------------------
void Copy_Folders_Files (AnsiString Src, AnsiString Dest)
  {  TSearchRec sr;
   if (FindFirst(Src+"\\*", faAnyFile, sr) == 0)
    {
      do
        {           if (sr.Attr & faDirectory) // directory
                    {
                     if (sr.Name!=".")
                     if (sr.Name!="..")
                      {
                      AnsiString SubFld = Src+"\\"+sr.Name;
                        if (!DirectoryExists(Dest+"\\"+ sr.Name))
                                CreateDir(Dest+"\\"+ sr.Name);
                                Copy_Folders_Files (SubFld, Dest+"\\"+ sr.Name);
                      }
                    }
                   else // file
                   {
                   if (sr.Name!=".")
                   if (sr.Name!="..")
                        {
                        AnsiString OldName = Src+"\\"+ sr.Name;
                        AnsiString NewName = Dest+"\\"+ sr.Name;
                        CopyFile(OldName.c_str(), NewName.c_str(), TRUE);
                        }
                  }
        }
             while (FindNext(sr) == 0);
             FindClose(sr);
    }
  }

 bool DeleteDir(AnsiString DirName)
 {
 TSearchRec sr;
 if (DirName.Length())
  {
  if (!FindFirst(DirName+"\\*.*",faAnyFile,sr))
   do
    {
     if (!(sr.Name=="." || sr.Name==".."))// это удалять не надо
       if (((sr.Attr & faDirectory) == faDirectory ) ||   (sr.Attr == faDirectory))// найдена папка
       {
         FileSetAttr(DirName+"\\"+sr.Name, faDirectory );// сброс всяких read-only
          DeleteDir(DirName+"\\"+sr.Name);//рекурсивно удаляем содержимое
          //RemoveDir(DirName + "\\"+sr.Name);// удаляем теперь уже пустую папку
       }
       else// иначе найден файл
           {    FileSetAttr(DirName+"\\"+sr.Name, 0);// сброс всяких read-only
                 DeleteFile(DirName+"\\"+sr.Name);// удаляем файл
           }
    }
                  while (!FindNext(sr));// ищем опять, пока не найдем все FindClose(sr);
    }
 RemoveDir(DirName);
 return true;

 }

void __fastcall TForm1::N2Click(TObject *Sender)
{     Form1->Visible=false;
      Form2->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
       Form4->Visible=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N4Click(TObject *Sender)
{
  Form6->Visible=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N5Click(TObject *Sender)
{   
  Form8->Visible=true;
}
//---------------------------------------------------------------------------


   


void __fastcall TForm1::N7Click(TObject *Sender)
{     AnsiString s=ExtractFilePath(Application->ExeName) + "\\Архив\\" + DateToStr(Date())+"\\" ;
        CreateDir(s);    //     создадим каталог!!!!
       AnsiString d=  ExtractFilePath(Application->ExeName) + "\\BD\\"  ;
   /* //copy all from program  files
    if(!MoveFiles("F:\\Autopark2\\copy\\*.*",  s))
    ShowMessage("Ok");
    else  ShowMessage("No");

     */
//AnsiString s="F:\\Autopark2\\Архив\\"+DateToStr(Date())+"\\" ;
Copy_Folders_Files (d , s)    ;
  ShowMessage("Данные успешно добавлены в " + s);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
  AnsiString path;
  AnsiString s=ExtractFilePath(Application->ExeName)+ "Архив\\" ;
  AnsiString d=  ExtractFilePath(Application->ExeName) + "\\BD\\"  ;
SelectDirectory("Выберите нужный вам архив...",s,path );
  //ShowMessage(path);
int buttonSelected=MessageDlg("Вы уверены что хотите загрузить этот архив, все имеющиеся данные будут удалены!",mtConfirmation	, mbOKCancel, 0);

  // Показ типа выбранной кнопки
  if (buttonSelected == 1 )
  {    ShowMessage("Загружаем!!!!");

     DeleteDir(d) ;   /// чистим старое

     Copy_Folders_Files (path , d)    ; //добовляем архив
  }
  if (buttonSelected == 2)
  {
  ShowMessage("Отменено!");
  }



}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\Архив\\OnOpening3\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\Архив\\OnOpening2\\" , ExtractFilePath(Application->ExeName) + "\\Архив\\OnOpening3\\");
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\Архив\\OnOpening2\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\Архив\\OnOpening1\\" , ExtractFilePath(Application->ExeName) + "\\Архив\\OnOpening2\\");
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\Архив\\OnOpening1\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\BD\\" , ExtractFilePath(Application->ExeName) + "\\Архив\\OnOpening1\\");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\Архив\\OnClosing3\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\Архив\\OnClosing2\\" , ExtractFilePath(Application->ExeName) + "\\Архив\\OnClosing3\\");
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\Архив\\OnClosing2\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\Архив\\OnClosing1\\" , ExtractFilePath(Application->ExeName) + "\\Архив\\OnClosing2\\");
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\Архив\\OnClosing1\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\BD\\" , ExtractFilePath(Application->ExeName) + "\\Архив\\OnClosing1\\");

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



