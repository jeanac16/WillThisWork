//---------------------------------------------------------------------------

#ifndef untMainH
#define untMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TButton *btnOne;
	TMemo *memOne;
	TEdit *edtOne;
	TButton *btnClose;
	TButton *Button1;
	TEdit *edtTwo;
	TButton *Button2;
	TButton *CleanMemo;
	TButton *btnOOP;
	TButton *btnFileViewer;
	void __fastcall btnCloseClick(TObject *Sender);
	void __fastcall btnOneClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall CleanMemoClick(TObject *Sender);
	void __fastcall btnOOPClick(TObject *Sender);
	void __fastcall btnFileViewerClick(TObject *Sender);


private:	// User declarations
    void __fastcall NewFunction();
    void __fastcall SomeVectorRelatedEx();

    void __fastcall DoSomething(AnsiString cars[]);
    void __fastcall AppendToMemo(String text);
    int  __fastcall FindFirstMissingInt(int A[], int iSize);
    int __fastcall HowManyContinuence(int A[], int iSize);

public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
