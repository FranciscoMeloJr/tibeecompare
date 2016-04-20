#include <stdio.h>
#include "MyTestLayer.h"
#include "volume.h"
#include "liblprprint.h"


JNIEXPORT void JNICALL Java_MyTestLayer_printmsg(JNIEnv *env, jobject obj, jdouble c, jdouble b, jdouble a)
{
/*This program is a JNI Layer for volume.cpp */
	printf("JNI Layer \n");
	double  num1 = a;
	double  num2 = b;
	double  num3 = c;
	printf("Volume for x %lf %lf %lf =%lf", num1, num2, num3, CalculateVolume(num1,num2,num3));
	lpr_print("JNI interface");
}


