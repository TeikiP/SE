#ifdef CHANGED
#include "syscall.h"

#define NB_THREADS 12
#define THIS "aaa"
#define THAT "bbb"

/*
*/

const int N = 10;

void puts(const char *s) {
	const char *p;
	for (p=s; *p!='\0'; p++)
		PutChar(*p);
}

void f(void *arg) {
	const char *s = arg;
	int i;

	for(i=0; i<N; i++)
		puts(s);

	PutChar('-');

	ThreadExit();
}

int main() {
	int i;

	for (i=0; i< NB_THREADS-1; i++)
		if (ThreadCreate(f, THIS) == -1)
			i--;

	f(THAT);

	ThreadExit();

	return 1;
}

#endif //CHANGED
