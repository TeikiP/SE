#ifdef CHANGED
#include "syscall.h"

/*
	A executer sans arguments.
	Affiche dans la console 4 caracteres successifs (ici 'abcd')
	suivi d'un retour a la ligne.
*/

void print(char c,int n) {
	int i;

	for(i=0;i<n;i++)
		PutChar(c+i);

	PutChar('\n');
}

int main() {
	print('a',4);

	return 1;
}

#endif //CHANGED
