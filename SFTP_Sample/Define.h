//---------------------------------------------------------------------------

#ifndef DefineH
#define DefineH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>

#include <stdio.h>
#include <iostream>

#include "tgputtylibcbclass.h"

class TClassDemo
{
  TTGPuttySFTP *PSFTP;
  public:
	bool DoVerifyHostKey(const char* host, const int port,
                         const char * fingerprint, const int verificationstatus,
                         bool &storehostkey);
	void DoMessage(const char* Msg, const bool isstderr);
	bool DoProgress(const __int64 bytescopied, const bool isupload);
	bool DoListing(const struct fxp_names* names);
	bool DoGetInput(char* linebuf, const int maxchars);
	void InitSFTP();
    void Run();
};




//---------------------------------------------------------------------------
#endif
