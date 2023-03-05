#ifndef _QMAPP_HF_DEF_STRUCT_
#define _QMAPP_HF_DEF_STRUCT_

#include "def\basic_types.h"

struct MidiHeaderInfo
{
    midi_format_t   format;
    uint16_t        ppq;
    uint16_t        track_count;
};

struct AnOption
{
    cstring_t midi_path;
    cstring_t log_path;
    bool force_operation;
};

typedef struct MidiHeaderInfo MidiHeaderInfo;
typedef struct AnOption AnOption;
#include "lang\structure.h"

#endif //#ifndef _QMAPP_HF_DEF_STRUCT_