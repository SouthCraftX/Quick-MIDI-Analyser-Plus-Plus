#include <stdio.h>

#include "functional\read_header.h"

int main()
{
    MidiHeaderInfo info;
    FILE* fhde = fopen("D:\\hlzl\\level_exclaim.mid" , "rb");

    if(!fhde)
    {
        perror("Open midi failed");
        abort();
    }

    errid_t ret =  read_header(&info , fhde);
    if( ret )
    {
        printf("Read Error:%i" , ret);
        abort();
    }

    printf("Format:\t%i\n""PPQ:\t%i\n""Track Count:\t%i" ,
            info.format , info.ppq , info.track_count);

}