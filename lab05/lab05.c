
/******************************************************************************
* Assignment:  <lab05>
* Lab Section: <tuesday, 1130, and SC289>
* Description: <User inputs minor and major axis lengths then eccentricty is calculated and compared to the eccentricty of the Earth's orbit the Moon's orbit, and a circle. The closest eccentricty is printed.>
* Programmers: <Jonathan Bruce bruce11@purdue.edu>
*              <Ivy Ma  ma262@purdue.edu>
*              <Bryan Chao bchao@purdue.edu>
* The person(s) listed above affirm that this is an original work and any
* violation of the academic integrity policy will be penalized.
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define E 0.0167
#define M 0.0549
#define C 0.00

// Function Declarations
  void input(long double*, long double*);
  void output(int, int, int, long double);
  long double calcEccen(long double, long double);
  void compEccen(int*, int*, int*, long double);


int main(void)
{
// Local Declarations
  long double majorAxis; // major axis of eclipse
  long double minorAxis; // minor axis of eclipse
  long double eccen; // eccectricity of elipse
  int factorM; // 1 if M is closest to eccentricity, else 0
  int factorE; // 1 if E is closest to eccentricity, else 0
  int factorC; // 1 if C is closest to eccentricity, else 0
// Statements
  //Input axises and determine eccen
  input(&majorAxis, &minorAxis);
  eccen = calcEccen(majorAxis, minorAxis);
  //determines which eccentricity is closest to eccen
  compEccen(&factorM, &factorE, &factorC, eccen);
  output(factorM, factorE, factorC, eccen); //print output
  return 0;
}  // main

/******************************************************************************
* Function:    <input>
* Description: <Asks user for the minor and major axis. Passes both by address>
* Parameters:  <majorAxis, long double by address, majorAxis length>
*              <minorAxis, long double by address, minor axis length>
* Return:      <void>
******************************************************************************/
void input(long double *majorAxis,long double *minorAxis)
{
// Statements
  printf("Enter the length of the minor axis: ");
  scanf("%Lf", &*minorAxis);
  printf("Enter the length of the major axis: ");
  scanf("%Lf", &*majorAxis);
  return;
} // input
/******************************************************************************
* Function:    <calcEccen>
* Description: <Calculate the eccentricity of an eclipse using major and minor axis lengths>
* Parameters:  <majorAxis, long double, length of majorAxis>
*              <minorAxis, long double, length of minorAxis>
* Return:      <long double, the eccentricty of the eclipse>
******************************************************************************/
long double calcEccen(long double majorAxis, long double minorAxis)
{
// Statements
  return sqrt(1 - (pow(minorAxis , 2) / pow(majorAxis , 2))); //calcEccen

}


/******************************************************************************
* Function:    <compEccen>
* Description: <Compares the eccentricty of the input eccen to the orbit of moon and earth and a circle, then by side effect assigns the closest eccentricity to its char value.>
* Parameters:  <factorM, int by address, factor for determining proximity to eccen>
*              <factorE, int by address, factor for determining proximity to eccen>
*              <factorC, int by address, factor for determining proximity to eccen>
*              <eccen, long double, eccentricty of user input eclipse>
* Return:      <void>
******************************************************************************/
void compEccen(int *factorM, int *factorE, int *factorC, long double eccen)
{
// Local Declarations
  long double diffC; // difference between C and eccen
  long double diffM; // difference between M and eccen
  long double diffE; // difference between E and eccen
// Statements
  diffC = fabsl(eccen - C) + 1;
  diffM = fabsl(eccen - M) + 1;
  diffE = fabsl(eccen - E) + 1;

// Compares differences, smallest difference = 1, others = 0.
  *factorC = (diffM / diffC); // 0 if diffC > diffM
  *factorC = (diffE / diffC)* *factorC; // 0 if diffC > diffE
   
  *factorM = (diffE / diffM);
  *factorM = (diffC / diffM)* *factorM;

  *factorE = (diffC / diffE);
  *factorE = (diffM / diffE) * *factorE;
// scales nonzero number to a 1
  *factorC = (*factorC + 2) % (*factorC + 1);
  *factorM = (*factorM + 2) % (*factorM + 1);
  *factorE = (*factorE + 2) % (*factorE + 1);

// Converts 1 to char number, leaves 0 as space
  *factorC = *factorC * 35 + 32;
  *factorM = *factorM * 45 + 32;
  *factorE = *factorE * 37 + 32;
  return; 
} //compEccen

/******************************************************************************
* Function:    <output>
* Description: <prints eccen and the closest eccentricty to eccen>
* Parameters:  <factorM, int, factor for determining proximity to eccen>
* *            <factorE, int, factor for determining proximity to eccen>
* *            <factorC, int, factor for determining proximity to eccen
*              <eccen, long double, eccentricty of user input eclipse>
* Return:      <void>
******************************************************************************/
void output(int factorM,int factorE,int factorC, long double eccen)
{
// Statements
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Eccentricity of ellipse:%11.5Lf", eccen);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Shape of orbit closest to: %2c %2c %2c", factorM, factorE, factorC);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  
  return;
} // output
