//*****************************************************************************
//
// MODULE           : LocalLock.h
//
// AUTHOR           : Tim Wöhrle, HTW
//
// CHANGES
// 2009-06-19: Migriert zu HTW-Projekt
//*****************************************************************************
// Klasse CLocalLock für schnelle, prozessinterne Sperren
//*****************************************************************************
#ifndef _LocalLock_H
#define _LocalLock_H

#include <windows.h>
#include <winbase.h>


//*****************************************************************************
// Klasse zum Einfachen Schützen kritischer Abschnitte innerhalb von Prozessen;
// *nicht* prozeß-übergreifend!
//*****************************************************************************
class CLocalLock
{
public:
   inline CLocalLock()
   { InitializeCriticalSection( &mSect );    }

   inline ~CLocalLock()
   { DeleteCriticalSection( &mSect );   }

   inline CLocalLock( const CLocalLock &pOther )
   { operator=( pOther );   }

   inline CLocalLock & operator=( const CLocalLock &pOther )
   {
      InitializeCriticalSection( &mSect );
      return *this;
   }

   inline void lock()
   { EnterCriticalSection( &mSect );   }

   inline void unlock()
   {  LeaveCriticalSection( &mSect );    }

   inline bool isLocked()
   {
      if( TryEnterCriticalSection( &mSect )==0 )
         return true;
      LeaveCriticalSection( &mSect );
      return false;
   }

private:
   CRITICAL_SECTION mSect;
};


//*****************************************************************************
// Klasse zum Verwalten einer Schreib-/Lesesperre;
// *nicht* prozeß-übergreifend!
//*****************************************************************************

class CReadWriteLock
{
public:
    inline CReadWriteLock(void);
    inline ~CReadWriteLock(void);
    
    //! Lock for reader access.
    inline void lockReader();
    //! Unlock reader access.
    inline void unlockReader();
    
    //! Lock for writer access.
    inline void lockWriter();
    //! Unlock writer access.
    inline void unlockWriter();

private:
    inline CReadWriteLock(const CReadWriteLock &cReadWriteLock);
    inline const CReadWriteLock& operator=(const CReadWriteLock &cReadWriteLock);

    inline void IncrementReaderCount();
    inline void DecrementReaderCount();

    HANDLE m_hWriterEvent;
    HANDLE m_hNoReadersEvent;
    int m_nReaderCount;
    
    CRITICAL_SECTION m_csLockWriter;
    CRITICAL_SECTION m_csReaderCount;
};



// Implementierung von CReadWriteLock

CReadWriteLock::CReadWriteLock(void)
 : m_nReaderCount(0), m_hWriterEvent(NULL), m_hNoReadersEvent(NULL)
{
    m_hWriterEvent    = CreateEvent(NULL, TRUE, TRUE, NULL);
    m_hNoReadersEvent = CreateEvent(NULL, TRUE, TRUE, NULL);
    InitializeCriticalSection(&m_csLockWriter);
    InitializeCriticalSection(&m_csReaderCount);
}

CReadWriteLock::CReadWriteLock(const CReadWriteLock &cReadWriteLock)
{
}

const CReadWriteLock& CReadWriteLock::operator=(const CReadWriteLock &cReadWriteLock)
{
    return *this;
}


CReadWriteLock::~CReadWriteLock(void)
{
    DeleteCriticalSection(&m_csLockWriter);
    DeleteCriticalSection(&m_csReaderCount);
    CloseHandle(m_hWriterEvent);
    CloseHandle(m_hNoReadersEvent);
}


void CReadWriteLock::lockReader()
{
    bool bLoop = true;

    while(bLoop)
    {
        WaitForSingleObject(m_hWriterEvent, INFINITE);
        IncrementReaderCount();
        if(WaitForSingleObject(m_hWriterEvent, 0) != WAIT_OBJECT_0)
        {
            DecrementReaderCount();
        }
        else
        {
            bLoop = false;
        }
    }
}


void CReadWriteLock::unlockReader()
{
    DecrementReaderCount();
}


void CReadWriteLock::lockWriter()
{
    EnterCriticalSection(&m_csLockWriter);
    WaitForSingleObject(m_hWriterEvent, INFINITE);
    ResetEvent(m_hWriterEvent);
    WaitForSingleObject(m_hNoReadersEvent, INFINITE); 
    LeaveCriticalSection(&m_csLockWriter);
}


void CReadWriteLock::unlockWriter()
{
    SetEvent(m_hWriterEvent);
}


void CReadWriteLock::IncrementReaderCount()
{
    EnterCriticalSection(&m_csReaderCount);
    m_nReaderCount++;
    ResetEvent(m_hNoReadersEvent);
    LeaveCriticalSection(&m_csReaderCount);
}


void CReadWriteLock::DecrementReaderCount()
{
    EnterCriticalSection(&m_csReaderCount);
    m_nReaderCount--;

    if(m_nReaderCount <= 0)
    {
        SetEvent(m_hNoReadersEvent);
    }

    LeaveCriticalSection(&m_csReaderCount);
}

#endif // _LocalLock_H




