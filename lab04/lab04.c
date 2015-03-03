
/******************************************************************************
* Assignment:  <Lab04>
* Lab Section: <Tues, 1130, SC 289>
* Description: Generates random triangle coordinates for 4 traingles and compares their areas. 
* Programmers: <Jonathan Bruce bruce11@purdue.edu>
*              <Chia-Hua Peng peng81@purdue.edu>
*              <Ivy Ma ma262@purdue.edu>
* The person(s) listed above affirm that this is an original work and any
* violation of the academic integrity policy will be penalized.
******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define LOWER -5
#define UPPER 5



// Function Declaration
int generateRandom(int lower, int upper);
int getInput (void);
float area(int x1, int y1, int x2, int y2, int x3, int y3);
float calcAreaDiff(float areaLarge, float areaSmall1, float areaSmall2, float areaSmall3);
void getOutput(int x1, int y1, int x2, int y2, int x3, int y3, float areaLarge, float areaSmall1, float areaSmall2, float areaSmall3,  float areaDiff);

int main(void)
{
// Local Declarations
  int seed;
  int x1; // x coordinate of the first point
  int y1; // y coordinate of the first point
  int x2; // x coordinate of the second point
  int y2; // y coordinate of the second point
  int x3; // x coordinate of the third point
  int y3; // y coordinate of the third point
  float areaLarge; // area of the large triangle
  float areaSmall1;// area of the small triangle #1
  float areaSmall2;// area of the small triangle #2
  float areaSmall3;// area of the small tirangle #3
  float areaDiff;  // difference between the large and small triangles

// Statements

  // recieve the seed
  seed = getInput();

  // generate random coordinates
  srand(seed);
  x1 = generateRandom(LOWER, UPPER);
  y1 = generateRandom(LOWER, UPPER);
  x2 = generateRandom(LOWER, UPPER);
  y2 = generateRandom(LOWER, UPPER);
  x3 = generateRandom(LOWER, UPPER);
  y3 = generateRandom(LOWER, UPPER);

  // calculate the area of triangles
  areaLarge = area(x1, y1, x2, y2, x3, y3);
  areaSmall1 = area(x1, y1, x2, y2, 0, 0);
  areaSmall2 = area(x3, y3, x2, y2, 0, 0);
  areaSmall3 = area(x3, y3, x1, y1, 0, 0);

  // calculate the difference between the large and small triangles
  areaDiff = calcAreaDiff(areaLarge, areaSmall1, areaSmall2, areaSmall3);

  // print the outputs
  getOutput(x1, y1, x2, y2, x3, y3, areaLarge, areaSmall1, areaSmall2, areaSmall3, areaDiff);
  
  return 0;
} // main

/******************************************************************************
* Function:    <getInput>
* Description: <recieve the input, seed>
* Parameters:  <void>
* Return:      <int seed for random generation>
******************************************************************************/
int getInput (void)
{
  int seed;
  printf("Enter seed value for random number generation: ");
  scanf("%d", &seed);
  return seed;
}//getInput

/******************************************************************************
* Function:    <generateRandom>
* Description: <Generates Random number>
* Parameters:  <lower, int, lower bounds for random number>
*              <upper, int, upper bounds for random number>
* Return:      <int random coordinate for new Triangle>
******************************************************************************/
int generateRandom(int lower, int upper)
{
// Local Declarations
  int coordinate;
  int range;

// Statements
  range = UPPER - LOWER + 1;
  coordinate = rand() % range + LOWER;
  return coordinate;
} // generateRandom


/******************************************************************************
* Function:    <area>
* Description: <calculate the area of a triangle using three x and y coordinates>
* Parameters:  <x1, int and x coordinate>
*              <y1, int and y coordinate>
*              <x2, int and x coordinate>
*              <y2, int and y coordinate>
*              <x3, int and x coordinate>
*              <y3, int and y coordinate>
* Return:      <float area of the triangle>
******************************************************************************/
float area (int x1, int y1, int x2, int y2, int x3, int y3)
{
  float area;
  
  //Calculate the area of the triangle using the coordinates
  area = fabs(((x1 - x3) * (y2 - y1) - (x1 - x2) * (y3 - y1)) / 2.0);
  return area;
}//area

/******************************************************************************
* Function:    <calcAreaDiff>
* Description: <calculate the difference between the large and small triangles>
* Parameters:  <areaLarge, float, area of the large triangle>
*              <areaSmall1, float, area of the first small triangle>
*              <areaSmall2, float, area of the second small triangle>
*              <areaSmall3, float, area of the third small triangle>
* Return:      <float the difference between the large and small triangles>
******************************************************************************/
float calcAreaDiff (float areaLarge, float areaSmall1, float areaSmall2, float areaSmall3)
{
  float difference;

  //calculate the difference between larger and smaller triangles
  difference = fabs(areaLarge - (areaSmall1 + areaSmall2 + areaSmall3));
  return difference;
}//calcAreaDiff

/******************************************************************************
* Function:    <getOutput>
* Description: <print the output>
* Parameters:  <x1, int and x coordinate>
*              <y1, int and y coordinate>
*              <x2, int and x coordinate>
*              <y2, int and y coordinate>
*              <x3, int and x coordinate>
*              <y3, int and y coordinate>
*              <areaLarge, float, area of the large triangle>
*              <areaSmall1, float, area of the first small triangle>
*              <areaSmall2, float, area of the second small triangle>
*              <areaSmall3, float, area of the third small triangle>
*              <areaDiff, float, difference between the large and small area>
* Return:      <void>
******************************************************************************/
void getOutput(int x1, int y1, int x2, int y2, int x3, int y3, float areaLarge, float areaSmall1, float areaSmall2, float areaSmall3,  float areaDiff)
{
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("\nGenerate Points: (%d, %d), (%d, %d), (%d, %d)\n", x1, y1, x2, y2, x3, y3);
  printf("\nArea of large triangle: %.1f\n", areaLarge);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("\nTriangle #1 Area (%d, %d), (%d, %d), (0, 0): %.1f", x1, y1, x2, y2, areaSmall1);
  printf("\nTriangle #2 Area (%d, %d), (%d, %d), (0, 0): %.1f", x3, y3, x2, y2, areaSmall2);
  printf("\nTriangle #3 Area (%d, %d), (%d, %d), (0, 0): %.1f", x3, y3, x1, y1, areaSmall3);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("\nDifference between larger and smaller triangles: %.1f\n", areaDiff);

}//getOutput


