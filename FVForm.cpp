//---------------------------------------------------------------------------
#include <fmx.h>
#include <IOUtils.hpp>
#pragma hdrstop

#include "FVForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uFrame1"
#pragma resource "*.fmx"
TfrmFileViewer *frmFileViewer;
//---------------------------------------------------------------------------
__fastcall TfrmFileViewer::TfrmFileViewer(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TfrmFileViewer::ShowMessage2(AnsiString msg) {
    memDrive->Text += msg;
}
//---------------------------------------------------------------------------
void __fastcall TfrmFileViewer::btnShowClick(TObject *Sender)
{
    System::DynamicArray<System::UnicodeString> lstDrives =
		TDirectory::GetLogicalDrives();

    for(int i = 0; i < lstDrives.Length; i++)
    {
        AnsiString strDrive = lstDrives[i];

        UINT drvType = GetDriveType((LPCWSTR)strDrive.c_str());

        if( drvType == DRIVE_NO_ROOT_DIR )
            ShowMessage2(L"Drive Name: " + lstDrives[i] + L"\n"
                L"The root path is invalid; for example,\n"
                L"there is no volume is mounted at the path\n\r");
        else if( drvType == DRIVE_REMOVABLE )
            ShowMessage2(L"Drive Name: " + lstDrives[i] + "\n"
                L"The drive has removable media; for example, "
                L"a floppy drive or flash card reader");
        else if( drvType == DRIVE_FIXED )
            ShowMessage2(L"Drive Name: " + lstDrives[i] + "\n"
                L"The drive has fixed media; for example, a hard "
                L"drive, flash drive, or thumb drive");
        else if( drvType == DRIVE_REMOTE )
            ShowMessage2(L"Drive Name: " + lstDrives[i] + "\n"
                L"The drive is a remote (network) drive");
        else if( drvType == DRIVE_CDROM )
            ShowMessage2(L"Drive Name: " + lstDrives[i] + "\n"
                L"The drive is a CD-ROM drive or a DVD drive");
        else if( drvType == DRIVE_RAMDISK )
            ShowMessage2(L"Drive Name: " + lstDrives[i] + "\n"
                L"The drive is a RAM disk");
        else //if( drvType == DRIVE_UNKNOWN )
            ShowMessage2(L"The drive type cannot be determined");
    }
}
//---------------------------------------------------------------------------
