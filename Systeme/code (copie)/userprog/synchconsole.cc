#ifdef CHANGED

#include "copyright.h"
#include "system.h"
#include "synchconsole.h"
#include "synch.h"

static Semaphore *readAvail;
static Semaphore *writeDone;

static void ReadAvailHandler(void* arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void* arg) { (void) arg; writeDone->V(); }

SynchConsole::SynchConsole(const char* in, const char *out)
{
	readAvail = new Semaphore("read avail", 0);
	writeDone = new Semaphore("write done", 0);
	console = new Console(in, out, ReadAvailHandler, WriteDoneHandler, 0);
}

SynchConsole::~SynchConsole()
{
	delete console;
	delete writeDone;
	delete readAvail;
}

void SynchConsole::SynchPutChar(int ch)
{
	console->PutChar(ch);
	writeDone->P();
}

int SynchConsole::SynchGetChar()
{
	readAvail->P();
	int ch = console->GetChar();
	return ch;
}

void SynchConsole::SynchPutString(const char s[])
{
	int i = 0;

	while (s[i] != '\0')
		SynchPutChar(s[i++]);

}

void SynchConsole::SynchGetString(char* s, int n)
{
	int i=0;
	do {
		s[i] = SynchGetChar();
	} while(s[i++] != '\n' && i < n-1);

	s[i]='\0';
}

#endif // CHANGED
