
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
#define _CRT_SECURE_NO_DEPRECATE


#include <cef_client.h>
#include <cef_app.h>
#include <capi/cef_app_capi.h>

#include <sstream>
#include <string>


#include <base/cef_bind.h>
#include <wrapper/cef_closure_task.h>
#include <cef_app.h>
#include <cef_base.h>
#include <base/cef_lock.h>
#include <wrapper/cef_helpers.h>


// Windows 头文件:
#include <windows.h>
#include <objbase.h>
#include <ShlObj.h>
#include <strsafe.h>
// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>