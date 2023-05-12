//---------------------------------------------------------------------------
#include <fmx.h>
#include <IOUtils.hpp>

//#include <windows.h>
//#include <fileapi.h>

#pragma hdrstop

using namespace System;

#include "uFrame1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyFrame1 *MyFrame1;
//---------------------------------------------------------------------------
__fastcall TMyFrame1::TMyFrame1(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyFrame1::btnDrivesClick(TObject *Sender)
{
	DynamicArray<UnicodeString> lstDrives = TDirectory::GetLogicalDrives();

	for(int i = 0; i < lstDrives.Length; i++)
		ShowMessage(lstDrives[i]);

	UnicodeString strHardDrive = lstDrives[0];
	ShowMessage(strHardDrive);
}
//---------------------------------------------------------------------------
