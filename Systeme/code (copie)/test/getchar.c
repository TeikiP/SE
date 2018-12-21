#ifdef CHANGED
#include "syscall.h"

/*
	A executer sans arguments.
	Recupere en entree un unique caractere avant de
	l'afficher dans la console et de se terminer.
*/

int main() {
	int ch;

	ch = GetChar();

	PutChar(ch);
}

#endif //CHANGED
