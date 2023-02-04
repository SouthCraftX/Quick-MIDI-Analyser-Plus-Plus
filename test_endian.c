#include <stdio.h>
#include "endian.h"
int main(){
#if defined(_QMAPP_BIG_ENDIAN_)
	puts("BE");
#elif defined(_QMAPP_LITTLE_ENDIAN_)
	puts("LE");
#else
#error "NO"
#endif
}
