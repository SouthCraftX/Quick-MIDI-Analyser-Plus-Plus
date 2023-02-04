#ifndef _QMAPP_HF_LANG_STRUCT_
#define _QMAPP_HF_LANG_STRUCT_

#include "def\basic_types.h"

enum {
    OK = 0,
    EID_BAD_PATH,
    EID_NO_FILE_SELECTED,
    EID_PERMISSION_DENIED,
    EID_BAD_HEADER_FLAG,
    EID_BAD_HEADER_SIZE,
    EID_UNSUPPORT_FORMAT,
    EID_BAD_ARG,
    EID_BAD_ARG_H,
    __ERRID_COUNT__ // 
} ErrID;

cstring_t error_msg[__ERRID_COUNT__];




#endif //#ifndef _QMAPP_HF_LANG_STRUCT_