
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



JNIEXPORT jstring JNICALL JAVA_JNISignalQuality_nativeSignalQuality(JNIEnv *env, jobject obj){

	HANDLE hClient = NULL;
	DWORD dwMaxClient = 2;
	DWORD dwCurVersion = 0;

	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
	PWLAN_INTERFACE_INFO pIfInfo = NULL;

	PWLAN_CONNECTION_ATTRIBUTES pConnectInfo = NULL;
	DWORD connectInfoSize = sizeof(WLAN_CONNECTION_ATTRIBUTES);
	WLAN_OPCODE_VALUE_TYPE opCode = wlan_opcode_value_type_invalid;

	WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
	WlanEnumInterfaces(hClient, NULL, &pIfList);

	pIfInfo = (WLAN_INTERFACE_INFO *)& pIfList->InterfaceInfo[0];

	WlanQueryInterface(hClient, &pIfInfo->InterfaceGuid, wlan_intf_opcode_current_connection, NULL, &connectInfoSize, (PVOID *)&pConnectInfo, &opCode);

	unsigned long sQuality = pConnectInfo->wlanAssociationAttributes.wlanSignalQuality;
	char* buf;

	sprintf(buf, 5, "%lu", sQuality);

	jstring ret = (*env)->NewStringUTF(env, buf);
	free(buf);

	return ret;
}