#ifdef CHANGED
#include "syscall.h"

/*
	A executer sans arguments.
	Lance deux programmes qui font chacun tourner le programme putchar.
*/

void launchProcess(const char *s, int nb) {
	int i;

	for (i=0; i<nb; i++)
		ForkExec(s);
}

int main() {
	launchProcess("./test/userpages0", 6);
	launchProcess("./test/userpages1", 6);

	return 1;
}

#endif //CHANGED
