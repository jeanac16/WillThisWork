//---------------------------------------------------------------------------

#ifndef uFrame1H
#define uFrame1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMyFrame1 : public TFrame
{
__published:	// IDE-managed Components
	TButton *btnDrives;
	void __fastcall btnDrivesClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMyFrame1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyFrame1 *MyFrame1;
//---------------------------------------------------------------------------
#endif
