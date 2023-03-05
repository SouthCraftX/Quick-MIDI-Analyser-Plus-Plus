#ifndef _QMAPP_HF_FUNATIONAL_READ_HD_
#   define _QMAPP_HF_FUNATIONAL_READ_HD_

#   include <stdio.h>
#   include "def.h"
#   include "lang\structure.h"
 
errid_t read_header(MidiHeaderInfo* header_info , FILE* midi_fhde)
{
    uint8_t header_buf[MF_HEADER_LEN];
    if( fread( header_buf , 1 , MF_HEADER_LEN , midi_fhde ) < MF_HEADER_LEN ){
        if(feof(midi_fhde))
        return EID_BAD_HEADER_SIZE;
    }
    
    if(*(uint32_t*)header_buf != MTHD_FLAG_U32)
        return EID_BAD_HEADER_FLAG;
    
    if(*(((uint32_t*)header_buf)+1) != HD_SIZE)
        return EID_BAD_HEADER_SIZE;

#   ifdef _QMAPP_BIG_ENDIAN_
    midi_format_t format = *(((uint16_t*)header_buf)+4);
#   else
    midi_format_t format = u16_be_to_le( *(((uint16_t*)header_buf)+4) );
#   endif

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

#   ifdef _QMAPP_BIG_ENDIAN_
    header_info->track_count = *(((uint16_t*)header_buf)+5);
    header_info->ppq = *(((uint16_t*)header_buf)+6);
#   else
    header_info->track_count = u16_be_to_le( *(((uint16_t*)header_buf)+5) );
    header_info->ppq = u16_be_to_le( *(((uint16_t*)header_buf)+6) );
#   endif
    return OK;
}

#endif //#ifndef _QMAPP_HF_FUNATIONAL_READ_HD_