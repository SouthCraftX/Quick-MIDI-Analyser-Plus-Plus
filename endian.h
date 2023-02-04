#ifndef _QMAPP_HF_ENDIAN_
#define _QMAPP_HF_ENDIAN_

#ifdef __BYTE_ORDER__

#if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#define _QMAPP_LITTLE_ENDIAN_
#else
#define _QMAPP_BIG_ENDIAN_
#endif //#ifdef __BYTE_ORDER__

#else

#if ('\x01\x02\x03\x04' == 0x01020304)   //BE
#define _QMAPP_BIG_ENDIAN_
#elif ('\x01\x02\x03\x04' == 0x04030201) //LE
#define _QMAPP_LITTLE_ENDIAN_
#else
#error "WTF? What endian do I meet?"
#endif //#if ...


#endif //#ifdef __BYTE_ORDER__

#include <stdint.h>

inline uint16_t u16_be_to_le(uint16_t x) {
    return ((x<<8)+(x>>8));
}

inline uint32_t u32_be_to_le(uint32_t x) {                                    
    uint8_t* _p = (uint8_t*)&x;                                    
    return  (((uint32_t)(*_p))+((uint32_t)*(_p+1)<<8)+       
            ((uint32_t)*(_p+2)<<16)+((uint32_t)*(_p+3)<<24));                                       
}

#endif //#ifndef _QMAPP_HF_ENDIAN_