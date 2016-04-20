// cin with strings
#include <iostream>
#include <string>
#include "gabriel.hpp"
#include "lib:wq"
using namespace std;

int main ()
{
  string mystr;
  cout << "What's your name? ";
  getline (cin, mystr);
  cout << "Hello " << mystr << ".\n";
  cout << "What is your favorite team? ";
  getline (cin, mystr);
  cout << "I like " << mystr << " too!\n";
  foo();
  return 0;
}
