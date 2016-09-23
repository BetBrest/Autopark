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
//InitialisePatchDB() - ��� ���� ������� ������� ���������� ���� � ����� ��
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
     if (!(sr.Name=="." || sr.Name==".."))// ��� ������� �� ����
       if (((sr.Attr & faDirectory) == faDirectory ) ||   (sr.Attr == faDirectory))// ������� �����
       {
         FileSetAttr(DirName+"\\"+sr.Name, faDirectory );// ����� ������ read-only
          DeleteDir(DirName+"\\"+sr.Name);//���������� ������� ����������
          //RemoveDir(DirName + "\\"+sr.Name);// ������� ������ ��� ������ �����
       }
       else// ����� ������ ����
           {    FileSetAttr(DirName+"\\"+sr.Name, 0);// ����� ������ read-only
                 DeleteFile(DirName+"\\"+sr.Name);// ������� ����
           }
    }
                  while (!FindNext(sr));// ���� �����, ���� �� ������ ��� FindClose(sr);
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
{     AnsiString s=ExtractFilePath(Application->ExeName) + "\\�����\\" + DateToStr(Date())+"\\" ;
        CreateDir(s);    //     �������� �������!!!!
       AnsiString d=  ExtractFilePath(Application->ExeName) + "\\BD\\"  ;
   /* //copy all from program  files
    if(!MoveFiles("F:\\Autopark2\\copy\\*.*",  s))
    ShowMessage("Ok");
    else  ShowMessage("No");

     */
//AnsiString s="F:\\Autopark2\\�����\\"+DateToStr(Date())+"\\" ;
Copy_Folders_Files (d , s)    ;
  ShowMessage("������ ������� ��������� � " + s);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
  AnsiString path;
  AnsiString s=ExtractFilePath(Application->ExeName)+ "�����\\" ;
  AnsiString d=  ExtractFilePath(Application->ExeName) + "\\BD\\"  ;
SelectDirectory("�������� ������ ��� �����...",s,path );
  //ShowMessage(path);
int buttonSelected=MessageDlg("�� ������� ��� ������ ��������� ���� �����, ��� ��������� ������ ����� �������!",mtConfirmation	, mbOKCancel, 0);

  // ����� ���� ��������� ������
  if (buttonSelected == 1 )
  {    ShowMessage("���������!!!!");

     DeleteDir(d) ;   /// ������ ������

     Copy_Folders_Files (path , d)    ; //��������� �����
  }
  if (buttonSelected == 2)
  {
  ShowMessage("��������!");
  }



}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\�����\\OnOpening3\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\�����\\OnOpening2\\" , ExtractFilePath(Application->ExeName) + "\\�����\\OnOpening3\\");
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\�����\\OnOpening2\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\�����\\OnOpening1\\" , ExtractFilePath(Application->ExeName) + "\\�����\\OnOpening2\\");
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\�����\\OnOpening1\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\BD\\" , ExtractFilePath(Application->ExeName) + "\\�����\\OnOpening1\\");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\�����\\OnClosing3\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\�����\\OnClosing2\\" , ExtractFilePath(Application->ExeName) + "\\�����\\OnClosing3\\");
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\�����\\OnClosing2\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\�����\\OnClosing1\\" , ExtractFilePath(Application->ExeName) + "\\�����\\OnClosing2\\");
    DeleteDir(ExtractFilePath(Application->ExeName) + "\\�����\\OnClosing1\\");
    Copy_Folders_Files (ExtractFilePath(Application->ExeName) + "\\BD\\" , ExtractFilePath(Application->ExeName) + "\\�����\\OnClosing1\\");

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



