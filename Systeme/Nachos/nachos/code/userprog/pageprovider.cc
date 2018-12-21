#ifdef CHANGED
#include <assert.h>
#include "pageprovider.h"
#include "bitmap.h"
#include "addrspace.h"
#include "machine.h"
#include "system.h"

PageProvider::PageProvider(int NumPages) {
	bitmap = new BitMap(NumPages);
	semBitMap = new Semaphore("semaphore BitMap",1);
	sizeBitMap=NumPages;
}

PageProvider::~PageProvider() {
	delete bitmap;
	delete semBitMap;
}

int
PageProvider::GetEmptyPage() {
	semBitMap->P();

	int page = bitmap->Find();

	assert(page != -1);
	memset(&(machine->mainMemory[page*PageSize]), 0, PageSize);

	semBitMap->V();

	return page;
}

void
PageProvider::ReleasePage(int nb) {
	semBitMap->P();
	bitmap->Clear(nb);
	semBitMap->V();
}

int
PageProvider::NumAvailPage() {
	semBitMap->P();
	int numAvail = bitmap->NumClear();
	semBitMap->V();
	return numAvail;
}

#endif // CHANGED
