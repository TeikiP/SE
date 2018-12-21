#ifdef CHANGED

#ifndef PAGEPROVIDER_H
#define PAGEPROVIDER_H

#include "bitmap.h"
#include "synch.h"

class PageProvider
{
  public:
    PageProvider (int NumPages);
    ~PageProvider ();
    int GetEmptyPage ();
    void ReleasePage (int nb);
    int NumAvailPage ();

  private:
    BitMap *bitmap;
    Semaphore *semBitMap;
    int sizeBitMap;
};

#endif // PAGEPROVIDER_H

#endif // CHANGED
