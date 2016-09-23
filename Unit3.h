//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TButton *Button1;
        TComboBox *ComboBox1;
        TLabel *Label2;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall ComboBox1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Button1Click(TObject *Sender);
       //void __fastcall FormKeyPress(TObject *Sender, char &Key);
        //void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key,
         // TShiftState Shift);
       // void __fastcall Edit1Enter(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
