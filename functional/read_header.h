#ifndef _QMAPP_HF_FUNATIONAL_READ_HD_
#define _QMAPP_HF_FUNATIONAL_READ_HD_

#include <stdio.h>
#include "def.h"
#include "lang\structure.h"
 
errid_t read_header(MidiHeaderInfo* header_info , FILE* mf_handle)
{
    uint8_t header_buf[MF_HEADER_LEN];
    if( fread( header_buf , 1 , MF_HEADER_LEN , mf_handle ) < MF_HEADER_LEN ){
        if(feof(mf_handle))
        return EID_BAD_HEADER_SIZE;
    }
    
    if(*(uint32_t*)header_buf != MTHD_FLAG_U32)
        return EID_BAD_HEADER_FLAG;
    
    if(*(((uint32_t*)header_buf)+1) != HD_SZIE)
        return EID_BAD_HEADER_SIZE;

    midi_format_t format = *(((uint16_t*)header_buf)+4);

    switch( format )
    {
        case FMT_SINGLETRACK:
        case FMT_MUILTTRACK:
        case FMT_SMPTETIME:
            header_info->format = format;
            break;
        default:
            return EID_UNSUPPORT_FORMAT;
    }

    header_info->ppq = *(((uint16_t*)header_buf)+5);

    return OK;
}

#endif //#ifndef _QMAPP_HF_FUNATIONAL_READ_HD_