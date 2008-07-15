#ifndef __X_SYNC_UTILS_
#define __X_SYNC_UTILS_

/*
 *      Copyright (C) 2005-2008 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "XCriticalSection.h"
#include "XHandle.h"

#ifdef _LINUX

#define STATUS_WAIT_0 ((DWORD   )0x00000000L)
#define WAIT_FAILED   ((DWORD)0xFFFFFFFF)
#define WAIT_OBJECT_0 ((STATUS_WAIT_0 ) + 0 )
#define WAIT_TIMEOUT  258L
#define INFINITE    0xFFFFFFFF
#define STATUS_ABANDONED_WAIT_0 0x00000080
#define WAIT_ABANDONED         ((STATUS_ABANDONED_WAIT_0 ) + 0 )
#define WAIT_ABANDONED_0       ((STATUS_ABANDONED_WAIT_0 ) + 0 )

HANDLE  WINAPI CreateMutex( LPSECURITY_ATTRIBUTES lpMutexAttributes,  BOOL bInitialOwner,  LPCTSTR lpName );
bool  InitializeRecursiveMutex(HANDLE hMutex, BOOL bInitialOwner);
bool  DestroyRecursiveMutex(HANDLE hMutex);
bool  WINAPI ReleaseMutex( HANDLE hMutex );

void GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer);

DWORD WINAPI WaitForSingleObject( HANDLE hHandle, DWORD dwMilliseconds );
DWORD WINAPI WaitForMultipleObjects( DWORD nCount, HANDLE* lpHandles, BOOL bWaitAll,  DWORD dwMilliseconds);

LONG InterlockedIncrement(  LONG * Addend );
LONG InterlockedDecrement(  LONG * Addend );
LONG InterlockedCompareExchange(
  LONG * Destination,
  LONG Exchange,
  LONG Comparand
);

LONG InterlockedExchange(
  LONG volatile* Target,
  LONG Value
);

int SDL_SemWaitTimeout2(SDL_sem *sem, Uint32 ms);

#endif

#endif

