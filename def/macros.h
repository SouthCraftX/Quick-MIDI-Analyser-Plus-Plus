#ifndef _QMAPP_HF_DEF_MACROS_
#define _QMAPP_HF_DEF_MACROS_

#if (defined(_WIN16) || defined(_WIN32) || defined(_WIN64)) && !defined(__WINDOWS__)
#define __WINDOWS__
#endif

#include "endian.h"

#if defined(_QMAPP_LITTLE_ENDIAN_)
#include <le\def\macros.h>
#elif defined(_QMAPP_BIG_ENDIAN_)
#include <be\def\macros.h>
#else
#error "Macros regarding endian is not defined.";
#endif //#if ...

#include "def\basic_types.h"

#define DIGMODE_ASKMIDI (0)
#define DIGMODE_ASKLOG  (1)

#define MAX_FNAME_LEN   (260)

#define FMT_SINGLETRACK (0)
#define FMT_MUILTTRACK  (1)
#define FMT_SMPTETIME   (2)

#define MF_HEADER_LEN   (6L)

#define LANG_ZH         (1)
#define LANG_EN         (2)
#define LANG_UNSPEC     (0) //未指定语言

#if defined(_QMAPP_LITTLE_ENDIAN_)
#define MTRK_FLAG_U32 MTRK_FLAG_U32_LE
#define MTHD_FLAG_U32 MTHD_FLAG_U32_LE
#define HD_SIZE HD_SIZE_BE //?
#elif defined(_QMAPP_BIG_ENDIAN_)
#define MTRK_FLAG_U32 MTRK_FLAG_U32_BE
#define MTHD_FLAG_U32 MTHD_FLAG_U32_BE
#define HD_SZIE HD_SIZE_BE //?
#endif //#if defined(...)

#endif //#ifndef _QMAPP_HF_DEF_MACROS_