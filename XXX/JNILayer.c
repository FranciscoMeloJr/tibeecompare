#include <stdio.h>
#include "MyTestLayer.h"
#include "volume.h"
#include "liblprprint.h"

/*
*
*/
JNIEXPORT jdouble JNICALL Java_MyTestLayer_volume
  (JNIEnv * env, jobject obj, jdouble a, jdouble b, jdouble c)
{
/*This program is a JNI Layer for volume.cpp and for a shared library lpr_print */
	printf("JNI Layer \n");
	double  num1 = a;
	double  num2 = b;
	double  num3 = c;
	printf("Volume for x %lf %lf %lf =%lf", num1, num2, num3, CalculateVolume(num1,num2,num3));
	
}
/*
 * Class:     MyTestLayer
 * Method:    printmsg
 * Signature: ([C)V
 */
JNIEXPORT void JNICALL Java_MyTestLayer_printmsg (JNIEnv *env, jobject obj, jcharArray Array)
{
	char* p = Array;
	lpr_print(p);
}


