//---------------------------------------------------------------------------
#include <fmx.h>
#pragma hdrstop

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#include "untMain.h"
#include "UClasses.h"
#include "FVForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfrmMain *frmMain;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnCloseClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnOneClick(TObject *Sender)
{
    memOne->Text = edtOne->Text;
    edtOne->Text = "Al Pacino";
    NewFunction();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::NewFunction() {

    // Case sensitive
    // if (CompareStr(edtOne->Text, edtTwo->Text) == 0) {
    // Not Case sensitive
    if (SameText(edtOne->Text, edtTwo->Text)) {
    	//ShowMessage("Yes they are equal.");
        AppendToMemo("yes, edtOne is equal to edtTwo... No Case Sensitive.");
    }else {
		//ShowMessage("Nope they are NOT.");
        AppendToMemo("No, the two edt fields are not the same.");
    }

    AnsiString Country("United States of America");
    AppendToMemo(Country);

    Country.Delete(7, 7);
	AppendToMemo(Country);

    SomeVectorRelatedEx();
}

void __fastcall TfrmMain::SomeVectorRelatedEx() {
    AnsiString cars[] = {"", "", ""};
    cars[0] = "One";
    cars[1] = "two";
    cars[2] = "three";
    AppendToMemo(cars->Length());
    for (int i = 0; i < 3; i++) {
        AppendToMemo(cars[i]);
    }

	vector<int> vec;
	int i;

    AppendToMemo("vector size = " + String( vec.size() ) );

    // push 5 values into the vector
    for(i = 0; i < 5; i++) {
      vec.push_back(i*10);
    }

    // display extended size of vec
    AppendToMemo("extended vector size = " + String( vec.size() ) );

    // access 5 values from the vector
    for(i = 0; i < 5; i++) {
    	AppendToMemo("value of vec [" + String(i) + "] = " + String(vec[i]));
    }

    // use iterator to access the values
    vector<int>::iterator v = vec.begin();
    while( v != vec.end()) {
    	AppendToMemo("value of v = " + String(*v));
		v++;
    }

    for (auto &th : vec) {
    	AppendToMemo("the values are: " + String(th));
  	}
}

void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
	AnsiString Country;
    String Country2 = "Lebanon";
    Country = "Madagascar";

    AnsiString City("Laval");
    String City2("Montreal");

    edtOne->Text = City2;
	AnsiString anS = edtOne->Text;
	memOne->Text = anS.Length();

    // you can take only first 4
    AnsiString res = anS.SetLength(4);
    res = anS.TrimLeft();
    res = anS.TrimRight()	;
    res = anS.Trim();

    String anS2 = edtOne->Text;
    res = anS2.UpperCase();	//LowerCase

    AnsiString fName("Johnny ");
    AnsiString lName("Abou-Chaker");
    AppendStr(fName, lName);

    AnsiString cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
    DoSomething(cars);

    AppendToMemo(fName);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::DoSomething(AnsiString cars[])
{
	//memOne->Lines->Clear();
    	
    for (int i = 0; i < cars->Length()-1; i++) {
		AppendToMemo(cars[i]);
    }
}
void __fastcall TfrmMain::AppendToMemo(String text) {
	// memOne->Lines->Append("\n\r");
    memOne->Lines->Append(text);
    
    AnsiString Msg("The number of lines:  ");
    //ShowMessage(Msg + IntToStr(memOne->Lines->Count));
}

bool __fastcall AContains(int A[], int iSize, int iVal){
 	int *end = A + iSize;
	int *result = std::find(A, end, iVal);
	return (result != end);
}

void WillThisWork() {
    ShowMessage("Yes Sir.");
}

void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
	int arr[] = {2, 3, 1, 4, 5, 10, 8};
    int iSize = sizeof(arr)/sizeof(arr[0]);
    
    int res = FindFirstMissingInt(arr, iSize);
    AppendToMemo("The first missing int in the array is: " + String(res));

    int tst = edtTwo->Text.ToIntDef(0);
    AppendToMemo(AContains(arr, iSize, tst) ?
    		"Found" : String(tst) + " in edtTwo was Not Found in array.") ;

    int arr2[] = {3, 1, 2, 4, 10, 5, 8};
    sort(begin(arr2), end(arr2));
    memOne->Text += "\n\r";
    for(int i=0;i<7;i++)
    	memOne->Text += i;

    //String sMsg = AnsiString("Size of array = ") + arrSize;
	//ShowMessage(sMsg);

    typedef String arrName[2];
    arrName empName;
    empName[0] = "His first name";
    empName[1] = "Last Name";

    res = HowManyContinuence(arr, iSize);
    AppendToMemo("   [ " + String(res) + " ]");
    
    const int arrSize = 7;
    int arrMy[arrSize] = {3, 2, 5, 1, 4, 7, 6};
    res = HowManyContinuence(arrMy, iSize);
    AppendToMemo("   [ " + String(res) + " ]");

    WillThisWork();
}


//---------------------------------------------------------------------------
int __fastcall TfrmMain::FindFirstMissingInt(int A[], int iSize)
{
	const int MaxValue = 32000;      // int.MaxValue
    for (int i = 1; i <= MaxValue; i++)
    {
        if (!AContains(A, iSize, i))
        {
            return i;
        }
    }
    return -1; // This should never happen
}

int __fastcall TfrmMain::HowManyContinuence(int A[], int iSize)
{
    AppendToMemo("new arr next:");
	for (int i=0; i < iSize; i++) {
        memOne->Text += " " + String(A[i]);
    }
    
    //var consecutiveNumbers = new HashSet<int>();
    set <int> consecNum;

    int iCount = 0;
    int startFrom = 1;

    //int len = (sizeof(arr)/sizeof(arr[0]);
    //

    for (int i = 0; i < iSize; i++)
    {
        consecNum.insert(A[i]);

        int maxLength = A[i] - startFrom + 1;
        if (consecNum.size() < maxLength)
        {
            continue;
        }

        bool bAllOn = true;
        auto iBeg = consecNum.begin();
        auto iEnd = consecNum.end();
        int maxVal = *max_element(iBeg, iEnd);

        for (int j = startFrom; j <= maxVal; j++)
        {
        	// if (!.Contains(j)
            if (consecNum.find(j) == consecNum.end())
            {
                bAllOn = false;
                break;
            }
        }

        if (bAllOn)
        {
            startFrom = maxVal + 1;
            iCount++;
            while(!consecNum.empty())
                consecNum.erase(consecNum.begin());
        }
    }

    return iCount;
}

/*
	char Pick = 'r';
    char NewLine = '\n';
    char FirstName[12];
	char LastName[12];
    char University[] = "University of the District of Columbia";
    char Faculty[]("Computer sciences");
*/

   // sprintf(buff, “%d + %d = %d”, x, y, x + y);

    /*
       Boolean Result = SameText(Password1, Password2);
       if(String1.AnsiCompareIC(String2) == 0)
       if(String1.AnsiCompare(String2) == 0)

       S.AnsiLastChar();  Last chr of a string

       if( Edit1.IsEmpty() )
    */

	/*int test = 0;
    Integer test2 = 101;
    INT aga = 202;
    short       Number1;
    Smallint    Number2;
    unsigned DayOfBirth, MonthOfBirth, YearOfBirth;
    unsigned short  Shirts;
    Word            Pants;
    USHORT          Dresses;
    WORD            Ties;
    long double, or an Extended
    Extended radius = 15.625
    long, redefined as DWord
    float or the Single
    */

//---------------------------------------------------------------------------

void __fastcall TfrmMain::CleanMemoClick(TObject *Sender)
{
    memOne->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnOOPClick(TObject *Sender)
{
	// Using object-oriented programming

    // Using Inheritance in C++
	BankAccount bankAcc(100.0);
  	bankAcc.deposit(50.0);
  	bankAcc.deposit(25.15);
  	bankAcc.withdraw(30);
  	bankAcc.addInterest();
 
  	AppendToMemo("bankAcc.getBalance():  " + String(bankAcc.getBalance()) );

    // Using Polymorphism in C++
    Shape* s;

    Triangle  tri;
    MyRectangle rec;
    Circle    circ;

    // store the address of Rectangle
    s = &rec;
    // call Rectangle Draw function
    AppendToMemo(s->Draw());

    // store the address of Triangle
    s = &tri;
    // call Triangle Draw function
    AppendToMemo(s->Draw());

    // store the address of Circle
    s = &circ;
    // call Circle Draw function
    AppendToMemo(s->Draw());

    
	// Abstraction and Encapsulation
    abstraction obj;
 
    obj.set(1, 2);
    AppendToMemo(obj.GetValuesToDisplay());
    obj.set(21, 12);
    AppendToMemo(obj.GetValuesToDisplay());
    
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnFileViewerClick(TObject *Sender)
{
	frmFileViewer->ShowModal();
}
//---------------------------------------------------------------------------

