#include <liblprprint.h>

/* To shorten example, not using argp to test a shared library above*/
int main ()
{
  lpr_print ("Hello, Multiverse!\nHowarya?\n");
  return 0;
}
