//---------------------------------------------------------------------------

#ifndef FVFormH
#define FVFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include "uFrame1.h"
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmFileViewer : public TForm
{
__published:	// IDE-managed Components
	TMyFrame1 *MyFrame11;
	TMemo *memDrive;
	TButton *btnShow;
	void __fastcall btnShowClick(TObject *Sender);
private:	// User declarations
    void __fastcall ShowMessage2(AnsiString msg);

public:		// User declarations
	__fastcall TfrmFileViewer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmFileViewer *frmFileViewer;
//---------------------------------------------------------------------------
#endif
