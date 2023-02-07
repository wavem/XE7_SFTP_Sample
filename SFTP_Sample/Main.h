//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include "Define.h"
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "AdvMemo.hpp"
//---------------------------------------------------------------------------
class TClassDemo;
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *___pnBase;
	TAdvMemo *memo;
	TButton *btn_Init;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btn_InitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);



public: // Basic Functions
	void __fastcall InitProgram();
    void __fastcall ExitProgram();
    void __fastcall PrintMsg(UnicodeString _str);

public: // SFTP Routine
	TClassDemo* m_pClassDemo;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
