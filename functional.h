#ifndef _QMAPP_HF_FUNCTIONAL_
#   define _QMAPP_HF_FUNCTIONAL_

#   include "def.h"

#   ifdef _MSC_VER
#       include <stdio.h>
#       define qma_fread(buf , size , count , pfile) _fread_nolock(buf , size , count , pfile)
#   elif _BSD_SOURCE || _SVID_SOURCE
#       define qma_fread(buf , size , count , pfile) fread_unlocked(buf , size , count , pfile)
#   else
#       define qma_fread(buf , size , count , pfile) fread(buf , size , count , pfile)
#   endif

#   include "functional\exit.h"
#   include "functional\mempool.h"
#   include "functional\arg_process.h"
#   include "functional\open_file_diglog.h"
#   include "functional\read_header.h"
#   include "functional\cmd_text_col.h"
#   include "functional\unifunc.h"

#   include "logsys\logsys.h"

#endif // #ifndef _QMAPP_HF_FUNCTIONAL_