#include  <iostream>
#include "volume.h"

using namespace std;
int main()
{
    double i,j,k;

    cout << "Hello";  
    cout << "Please enter the width";
    cin >> i;

    cout << "Please enter an integer value: ";
    cin >> j;

    cout << "Please enter an integer value: ";
    cin >> k;

    cout<<"Volume is" << CalculateVolume(i,j,k);   

    return 0;
}
