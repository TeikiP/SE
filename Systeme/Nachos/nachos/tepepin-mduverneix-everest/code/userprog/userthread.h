#ifdef CHANGED
#include "addrspace.h"

typedef struct {
	int func;
	int arg;
} structSchmurtz;

extern int do_ThreadCreate(int f, int arg);
static void StartUserThread(void* schmurtz);
void do_ThreadExit();

#endif // CHANGED
