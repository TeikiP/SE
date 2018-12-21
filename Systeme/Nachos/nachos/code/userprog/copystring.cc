#ifdef CHANGED

#include "copyright.h"
#include "system.h"
#include "copystring.h"
#include "../machine/machine.h"

int copyStringFromMachine(int from, char* to, unsigned int size) {
	unsigned int i = 0;
        int c;

	for (; i < size && i < MAX_STRING_SIZE-1; i++) {
		machine->ReadMem(from+i, sizeof(char), &c);
                to[i]=(char) c;

		if (to[i] == '\0')
			break;
	}

	to[i] = '\0';

	return i;
}

int copyStringToMachine(char* from, int to, unsigned int size) {
	unsigned int i = 0;
	int c;

	for (; i < size && i < MAX_STRING_SIZE-1; i++) {
		c = (int) from[i];
		machine->WriteMem(to+i, sizeof(char), c);

		if (from[i] == '\0')
			break;
	}

	c = (int) '\0';
	machine->WriteMem(to+i, sizeof(char), c);

	return i;
}

#endif // CHANGED
