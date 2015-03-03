
/******************************************************************************
* Assignment:  <either Lab # or Homework #>
* Lab Section: <the day, time, and location of your lab meeting>
* Description: <verbose description of what the program does>
* Programmers: <fullname1 login1@purdue.edu>
*              <fullname2 login2@purdue.edu>
*              <fullname3 login3@purdue.edu>
* The person(s) listed above affirm that this is an original work and any
* violation of the academic integrity policy will be penalized.
******************************************************************************/
#include <stdio.h>

int main()
{
int x = 34;
int y = 712;
int z = 9;
float i = 13.14159;

printf("x: %9d\n", x);
printf("y: %9d\n", y);
printf("z: %9d\n", z);
printf("x: %-9d\n", x);
printf("y: %-9d\n", y);
printf("z: %-9d\n", z);

printf("i: %9.2f\n", i);
printf("i: %9.3f\n", i);

printf("i: %.2f\n", i);
printf("i: %1.2f\n", i);
printf("i: %f\n", i);

printf("i: %-9.2f\n", i);
printf("i: %-9.4f\n", i);
return 0;
}
