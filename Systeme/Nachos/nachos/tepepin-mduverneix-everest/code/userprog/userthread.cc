#ifdef CHANGED
#include "userthread.h"
#include "thread.h"
#include "syscall.h"
#include "system.h"


int do_ThreadCreate(int f, int arg) {
	//currentThread->space->IncrementCounter();

	if (currentThread->space->FindFreeBit() == -1)
		return -1;

	structSchmurtz *args = new structSchmurtz;

	args->func = f;
	args->arg = arg;

	Thread *newThread = new Thread("Nouveau thread");

	if (newThread == NULL)
		return -1;

	newThread->Start(StartUserThread, (void*) args);

	return 0;
}

static void StartUserThread(void *schmurtz) {
	DEBUG('x', "Debug StartUserThread : %s\n", schmurtz);

	int f = ((structSchmurtz*) schmurtz)->func;
	int arg = ((structSchmurtz*) schmurtz)->arg;

   	machine->WriteRegister (PCReg, f);
    	machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4 );
	machine->WriteRegister (4, arg);

	int stackTop = currentThread->space->AllocateUserStack();
    	machine->WriteRegister (StackReg, stackTop);
    	DEBUG ('a', "Initializing stack register to 0x%x\n", stackTop);

	currentThread->mapPosition = stackTop;

	machine->Run();
}

void do_ThreadExit() {
	//currentThread->space->DecrementCounter();

	currentThread->space->ClearBit(currentThread->space->GetBitFromStack(currentThread->mapPosition));

	if (currentThread->space->GetCounter() == 0) {
		DecCounterProcess();

		delete currentThread->space;

                if (IsProcessRunning())
			currentThread->Finish();

                else
                        interrupt->Halt();

	}

	else {
		currentThread->Finish();
	}
}

#endif //CHANGED
