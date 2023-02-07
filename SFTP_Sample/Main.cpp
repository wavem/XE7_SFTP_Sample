//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvMemo"
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
	InitProgram();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	ExitProgram();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ExitProgram() {

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::InitProgram() {

	m_pClassDemo = new TClassDemo;
	PrintMsg(L"Init Complete");
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::PrintMsg(UnicodeString _str) {
	int t_Idx = memo->Lines->Add(_str);
    memo->SetCursor(0, t_Idx);
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::btn_InitClick(TObject *Sender)
{
	// Common
    UnicodeString tempStr = L"";

	// Init Routine
    //m_pClassDemo->InitSFTP();
    m_pClassDemo->PSFTP = new TTGPuttySFTP(true);

    // Print Library Version
    tempStr.sprintf(L"Using %s", (UnicodeString)m_pClassDemo->PSFTP->GetLibVersion());
    PrintMsg(tempStr);

    // Input Host & User Info
    std::string host = "10.123.1.35";
    std::string user = "tcmsuser";
    std::string pw = "12345";
    m_pClassDemo->PSFTP->HostName = host;
	m_pClassDemo->PSFTP->UserName = user;
    m_pClassDemo->PSFTP->Password = pw;
    m_pClassDemo->PSFTP->Port = 22;

    // Set Event Functions
    m_pClassDemo->PSFTP->OnVerifyHostKey = m_pClassDemo->DoVerifyHostKey;
    m_pClassDemo->PSFTP->OnMessage = m_pClassDemo->DoMessage;
	m_pClassDemo->PSFTP->OnProgress = m_pClassDemo->DoProgress;
	m_pClassDemo->PSFTP->OnListing = m_pClassDemo->DoListing;
	m_pClassDemo->PSFTP->OnGetInput = m_pClassDemo->DoGetInput;


    //PSFTP = new TTGPuttySFTP(true);

    return;
#if 0
    printf("Using %s\n",PSFTP->GetLibVersion());


	printf("Enter hostname (URL/IP):\n");
	std::string host;
	std::getline(std::cin, host);

	printf("Enter username:\n");
	std::string user;
	std::getline(std::cin, user);

	PSFTP->HostName = host;
	PSFTP->UserName = user;
    PSFTP->Port = 22;

    printf("Enter password for %s:\n",PSFTP->HostName.c_str());

    std::string pw;
    std::getline(std::cin,pw);

    PSFTP->Password = pw;

    PSFTP->OnVerifyHostKey = DoVerifyHostKey;

	PSFTP->OnMessage = DoMessage;

	PSFTP->OnProgress = DoProgress;
	PSFTP->OnListing = DoListing;
	PSFTP->OnGetInput = DoGetInput;
#endif

}
//---------------------------------------------------------------------------

