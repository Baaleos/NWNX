/***************************************************************************
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#if !defined(NWNXCONNECT_H_)
#define NWNXCONNECT_H_
#define _CRT_SECURE_NO_WARNINGS

#include "../NWSERVER/types.h"
#include "../NWNXdll/NWNXBase.h"
#include "../NWSERVER/nwnx_memory.h"
#include <time.h>
#include "StackWalker.h"

#define OBJECT_INVALID 0x7F000000

class CNWNXStack : public CNWNXBase  
{
public:

	~CNWNXStack();

	BOOL OnCreate(const char* LogDir);
	char* OnRequest(char *gameObject, char* Request, char* Parameters);
	unsigned long OnRequestObject (char *gameObject, char* Request);
	BOOL OnRelease();
	void Log( const char * formatting, ... );
	void WriteLogHeader( );

	bool isOn;

	int listlen;
	void * MSW;

protected:

private:

};

class MyStackWalker : public StackWalker
{
public:
  MyStackWalker() : StackWalker() {}
  CNWNXStack * pThis;
protected:
  virtual void OnOutput(LPCSTR szText);
};

#endif