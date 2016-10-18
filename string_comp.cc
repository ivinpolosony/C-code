#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */
#include <iostream>
#include <string>
int main ()
{
  char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
  char * pEnd;
  std::string str = "hello";
  printf(str.c_str());
  long int li1, li2, li3, li4;
  li1 = strtol (szNumbers,&pEnd,10);
  li2 = strtol (pEnd,&pEnd,16);
  li3 = strtol (pEnd,&pEnd,2);
  li4 = strtol (pEnd,NULL,0);
  printf ("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
  return 0;
}