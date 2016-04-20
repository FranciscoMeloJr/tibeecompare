#include<stdio.h>

/*This main function will test the shared library that was created*/
int main(int argc, char *argv[] ) 
{
 	printf("Test shared library function");
	printf("Entry 3 numbers in sequence");
	double c;
	
	double num1 =	atof(argv[1]);
	double num2 =   atof(argv[2]); 
	double num3 =   atof(argv[3]); 
	printf ("%lf %lf %lf", num1, num2, num3);
	
	CalculateVolume(num1, num2, num3);

	return 0;
}
