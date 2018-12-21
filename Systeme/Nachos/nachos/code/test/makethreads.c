#ifdef CHANGED
#include "syscall.h"

/*      
	A executer sans arguments.
	Tente de créer 9 threads qui executent chacun la fonction f avec un char différent pour argument.
	La fonction f affiche ce caractère 3 fois avant de mettre fin à son propre thread.
	En cas d'échec lors de la création d'un thread, celui-ci est signalé par une sortie dans la console.
*/


void f (void *arg) {
	char* c = arg;
	volatile int i;

	for(i=0; i<3; i++)
		PutChar(*c);

	ThreadExit();
}

int main () {
	char chars[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int i;
	int returnValue;


	for (i=0; i<9; i++) {
		returnValue = ThreadCreate(f, &chars[i]);

		if (returnValue == -1)
			PutString("ECHEC\n");
	}

	PutString("Hello Main\n");

	ThreadExit();

	return 1;
}

#endif //CHANGED
