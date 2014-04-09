

#include "JNISignalQuality.h"
#include <stdio.h>

int wmain(){

	unsigned long percent = Java_JNISignalQuality_nativeSignalQuality(NULL,NULL);

	printf("%lu\n",percent);

	return 0;
}
