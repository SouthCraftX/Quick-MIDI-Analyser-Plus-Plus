#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "def.h"
#include "functional.h"


int main(uint32_t argn , cstring_t* argv)
{
    AnOption opt;
    MidiHeaderInfo header_info;
    FILE* mf_handle;

    switch( arg_process(argn , argv , &opt) )
    {
        case OK:
            break;
    
        case EID_BAD_ARG_H:
            break;

        case EID_BAD_ARG:
            break;

        default:
            break;
    }   

    mf_handle = fopen(opt.midi_path , "rb");
    if(!mf_handle){

    }
    
    switch( read_header(&header_info , mf_handle) )
    {
        case EID_BAD_HEADER_FLAG:
            break;

        case EID_BAD_HEADER_SIZE:
            break;

        default:

    }

}
