#ifdef CHANGED

#include "system.h"
#include "addrspace.h"
#include "userprocess.h"

static void StartUserProcess(void *schmurtz) {
        DEBUG('x', "Debug StartUserProcess : %s\n", schmurtz);

        currentThread->space->InitRegisters();
        currentThread->space->RestoreState();

        machine->Run();
        ASSERT(FALSE);
}

void do_ForkExec(const char *s) {
	IncCounterProcess();

	OpenFile *executable = fileSystem->Open (s);
	AddrSpace *space;

        if (executable == NULL) {
		printf ("Unable to open file %s\n", s);
		DecCounterProcess();
		return;
        }

        space = new AddrSpace (executable);

	Thread *userThread = new Thread("UserProcess");

	if (userThread == NULL) {
		printf("Erreur de creation du thread\n");
		DecCounterProcess();
		return;
	}

	userThread->space = space;

	userThread->Fork(StartUserProcess,0);

	currentThread->Yield();

        delete executable;
}

#endif // CHANGED
