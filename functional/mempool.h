#ifndef _QMA_HF_MEMPOOL_
#define _QMA_HF_MEMPOOL_

#   include "def.h"

#   ifdef __WINDOWS__
#       include <WinBase.h>
        HANDLE __win_process_heap_;
#       define sys_heapalloc_thrdsafe(size) HeapAlloc(__win_process_heap_ , 0 , size)
#       define sys_heapalloc(size) HeapAlloc(__win_process_heap_ , HEAP_NO_SERIALIZE , size)
#   endif // #ifdef __WINDOWS__

local struct
{
    uint16_t slice_n;
    void* mem;
} _mempool_host;

errid_t memp_init(uint16_t slice_n )
{
    _mempool_host.mem = sys_heapalloc( slice_n * MEMPOOL_SLICE_SZ );
    if(!_mempool_host.mem)
        return EID_OUTOFMEM;

    _mempool_host.slice_n = slice_n;
}

QMA_FORCE_INLINE
void* memp_get_current_slice(uint16_t index)
{
   return _mempool_host.mem + MEMPOOL_SLICE_SZ * index; 
}


#endif // #ifndef _QMA_HF_MEMPOOL_