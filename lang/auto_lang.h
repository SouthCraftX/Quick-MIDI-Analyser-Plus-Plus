#ifndef _QMAPP_HF_INIT_AUTOLANG_
#define _QMAPP_HF_INIT_AUTOLANG_

#include "def.h"
#include "set_lang.h"

#ifdef __WINDOWS__

#include <windows.h>

lang_id_t get_sys_lang()
{
    LANGID lang = GetUserDefaultUILanguage();
    return ((lang == 0x0804)||(lang == 0x1004))?LANG_ZH:LANG_EN;
    // 0x0804 ZH_CN 中文（中国）
    // 0x1004 ZH_SG 中文（新加坡）
}

#else

#include <stdlib.h>

lang_id_t get_sys_lang()
{
    //简体中文系统上：zh_CN.UTF-8
    cstring_t lang_token = getenv("LANG");
    if(!lang_token) return LANG_EN;
    return (!strncmp(lang_token,"zh",(unsigned)2))?LANG_ZH:LANG_EN;
}

#endif //#ifdef __WINDOWS__

void auto_lang(lang_id_t lang)
{
    switch (lang)
    {
        case LANG_UNSPEC:
            switch (get_sys_lang())
            {
                case LANG_ZH:
                    set_lang_zh();
                    break;

                case LANG_EN:
                    set_lang_zh();
                    break;

                default:
                    abort();
                    break;
            }
            break;

        case LANG_EN:
            set_lang_en();
            break;

        case LANG_ZH:
            set_lang_zh();
            break;
            
        default:
            abort();
            break;
    }
}
#endif //#ifndef _QMAPP_HF_INIT_AUTOLANG_