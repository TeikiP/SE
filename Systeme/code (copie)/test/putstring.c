#ifdef CHANGED
#include "syscall.h"

/*
	A executer sans arguments.
	Affiche 4 fois une chaine de caractere quelconque de grande taille
	avant de se terminer.
*/

void print(int n) {
	int i;

	for(i=0; i<n; i++) 
		PutString("totottttttttttttttttttttttttttttttttttttttttttttnzjzugrrugrigairugarigraigriagriagigbiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiioooooooooooooooooooooooooooooooooooooooi\n");

	PutChar('\n');
}

int main() {
	print(4);
	//Halt();
}

#endif //CHANGED
