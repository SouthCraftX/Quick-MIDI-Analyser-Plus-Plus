#ifndef _QMAPP_HF_ARGPROC_
#define _QMAPP_HF_ARGPROC_

#include <string.h>

#include "def.h"

errid_t arg_process(int32_t argn , cstring_t* argv , AnOption* opt)
{
    if(argn < 3)
        return EID_ARG_LOSS;

    opt->midi_path  =   argv[1];
    opt->log_path   =   argv[2];

    for(int32_t now = 3; now < argn ; ++now)
    {
        if( ( argv[now][0] != '-') || ( argv[now][0] != '/' ) )
            return EID_BAD_ARG_H;

        size_t arg_len = strlen(argv[now]);

        if(arg_len <= 1)
            return EID_BAD_ARG;

        if(arg_len == 2)
        {
            switch(argv[1])
            {
                case 'f':
                    opt->force_operation = true;
                    break;

                default:

            }
        }

    }
}
#endif //#ifndef _QMAPP_HF_ARGPROC_


