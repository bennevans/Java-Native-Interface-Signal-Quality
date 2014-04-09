
#include <jni.h>
#include "JNISignalQuality.h"

#include <stdio.h>
#include <tchar.h>

#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <wlanapi.h>
#include <windot11.h>
#include <objbase.h>
#include <wtypes.h>
#include <stdlib.h>

#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")