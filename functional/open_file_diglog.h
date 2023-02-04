#ifndef _QMAPP_HF_FUNCTIONAL_OFDIGLOG_
#define _QMAPP_HF_FUNCTIONAL_OFDIGLOG_

#include <windows.h>

#include "def.h"

errid_t ask_user_file_name(cwstring_t file_name , flag8_t mode){

    OPENFILENAME open_info = { };

    open_info.lStructSize = sizeof(OPENFILENAME);
    open_info.hwndOwner = NULL;

    switch( mode )
    {
        case DIGMODE_ASKMIDI:
            open_info.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST |
                      OFN_ENABLESIZING;
            open_info.lpstrFilter = TEXT("MIDI(*.mid)\0*.mid\0\0");
            break;
        
        case DIGMODE_ASKLOG:
            open_info.Flags = OFN_EXPLORER | OFN_ENABLESIZING;
            open_info.lpstrFilter = TEXT("Log file(*.txt)\0*.txt\0\0");
            break;

        default:
            abort();
    }
    
    open_info.lpstrFile = file_name;
    open_info.nMaxFile = MAX_FNAME_LEN;
    open_info.lpstrCustomFilter = NULL;

    if( GetOpenFileName(&open_info) )
        return EID_NO_FILE_SELECTED;

    return OK;
}

#endif //#ifndef _QMAPP_HF_FUNCTIONAL_OFDIGLOG_