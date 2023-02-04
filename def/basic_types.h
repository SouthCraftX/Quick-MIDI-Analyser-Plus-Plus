#ifndef _QMAPP_HF_DEF_BASIC_TYP_
#define _QMAPP_HF_DEF_BASIC_TYP_

#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>

typedef     int8_t      flag8_t   ;
typedef     int16_t     flag16_t  ;
typedef     int32_t     flag32_t  ;
typedef     int64_t     flag64_t  ;

typedef     char*           cstring_t  ;
typedef     const char*     ccstring_t ;
typedef     wchar_t*        cwstring_t ;
typedef     const wchar_t*  ccwstring_t;

typedef     flag16_t    lang_id_t;

typedef     flag8_t     midi_format_t;
typedef     flag32_t    errid_t;
#endif //#ifndef _QMAPP_HF_DEF_BASIC_TYP_