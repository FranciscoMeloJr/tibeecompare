#include <module.h
#include "handle.h"

JNIEXPORT jdouble JNICALL Java_Wrapper_Volume (JNIEnv *, jobject, jdouble, jdouble, jdouble)
{
	return CalculateVolume();
	
}
