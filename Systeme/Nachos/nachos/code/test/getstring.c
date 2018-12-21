#ifdef CHANGED
#include "syscall.h"

/*
	A executer sans arguments.
	Recupere en entree une chaine de 50 caracteres au maximum
	et l'affiche a la console avant de se terminer.

*/

int main() {
	char s[50];
	GetString(s, 50);
	PutString(s);
}

#endif // CHANGED
