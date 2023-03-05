#ifndef _QMAPP_HF_DEF_MACROS_
#   define _QMAPP_HF_DEF_MACROS_

#   define local static

#   if defined(__GNUC__) || defined(__clang__)
#       define QMA_FORCE_INLINE __attribute__((always_inline))
#   elif defined(_MSC_VER)
#       define QMA_FORCE_INLINE __forceinline
#   else
#       define QMA_FORCE_INLINE inline
#   endif // #ifdef __GNUC__

enum
{
    OK = 0,
    EID_BAD_PATH,
    EID_NO_FILE_SELECTED,
    EID_PERMISSION_DENIED,
    EID_BAD_HEADER_FLAG,
    EID_BAD_HEADER_SIZE,
    EID_UNSUPPORT_FORMAT,
    EID_BAD_ARG,
    EID_BAD_ARG_H,
    EID_OUTOFMEM,
    __ERRID_COUNT__ 
} ErrID;

#   if (defined(_WIN16) || defined(_WIN32) || defined(_WIN64)) && !defined(__WINDOWS__)
#       define __WINDOWS__
#   endif

#   include "endian.h"

#   if defined(_QMAPP_LITTLE_ENDIAN_)
#       include "le\def\macros.h"
#   elif defined(_QMAPP_BIG_ENDIAN_)
#       include "be\def\macros.h"
#   else
#       error "Macros regarding endian is not defined.";
#   endif //#if ...

#   include "def\basic_types.h"

#   define DIGMODE_ASKMIDI (0)
#   define DIGMODE_ASKLOG  (1)

#   define MAX_FNAME_LEN   (260)

#   define FMT_SINGLETRACK (0)
#   define FMT_MUILTTRACK  (1)
#   define FMT_SMPTETIME   (2)

#   define MF_HEADER_LEN   (14L)

#   define LANG_ZH         (1)
#   define LANG_EN         (2)
#   define LANG_UNSPEC     (0) //未指定语言

#   define MEMPOOL_SLICE_SZ (131072L) //128KB

#   if defined(_QMAPP_LITTLE_ENDIAN_)
#       define MTRK_FLAG_U32 MTRK_FLAG_U32_LE
#       define MTHD_FLAG_U32 MTHD_FLAG_U32_LE
#       define HD_SIZE HD_SIZE_LE //?
#   elif defined(_QMAPP_BIG_ENDIAN_)
#       define MTRK_FLAG_U32 MTRK_FLAG_U32_BE
#       define MTHD_FLAG_U32 MTHD_FLAG_U32_BE
#       define HD_SZIE HD_SIZE_BE //?
#   endif //#if defined(...)



#endif //#ifndef _QMAPP_HF_DEF_MACROS_