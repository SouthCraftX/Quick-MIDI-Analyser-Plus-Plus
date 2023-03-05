#ifndef _QMA_HF_INIT_
#define _QMA_HF_INIT_

#   include "def.h"

#   ifdef __WINDOWS__
#       include <WinBase.h>
        extern HANDLE __win_process_heap_;
#   endif

void init()
{

#   ifdef __WINDOWS__
    __win_process_heap_ = GetProcessHeap();
#   endif

}

#endif // #ifndef _QMA_HF_INIT_