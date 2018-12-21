#ifdef CHANGED

#include "copyright.h"
#include "system.h"
#include "synchconsole.h"
#include "synch.h"

static Semaphore *readAvail;
static Semaphore *writeDone;
static Semaphore *semChar;
static Semaphore *semString;

static void ReadAvailHandler(void* arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void* arg) { (void) arg; writeDone->V(); }

SynchConsole::SynchConsole(const char* in, const char *out)
{
	readAvail = new Semaphore("read avail", 0);
	writeDone = new Semaphore("write done", 0);

	semChar = new Semaphore("semChar", 1);
	semString = new Semaphore("semString", 1);

	console = new Console(in, out, ReadAvailHandler, WriteDoneHandler, 0);
}

SynchConsole::~SynchConsole()
{
	delete console;

	delete writeDone;
	delete readAvail;

	delete semChar;
	delete semString;
}

void SynchConsole::SynchPutChar(int ch)
{
	semChar->P();
	console->PutChar(ch);
	writeDone->P();
	semChar->V();
}

int SynchConsole::SynchGetChar()
{
	semChar->P();
	readAvail->P();
	int ch = console->GetChar();
	semChar->V();
	return ch;
}

void SynchConsole::SynchPutString(const char s[])
{
	semString->P();
	int i = 0;

	while (s[i] != '\0')
		SynchPutChar(s[i++]);
	semString->V();
}

void SynchConsole::SynchGetString(char* s, int n)
{
	semString->P();
	int i=0;
	do {
		s[i] = SynchGetChar();
	} while(s[i++] != '\n' && i < n-1);

	s[i]='\0';
	semString->V();
}

#endif // CHANGED
