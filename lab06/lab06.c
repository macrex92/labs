
/******************************************************************************
 * * Assignment:  <Lab #06>
 * * Lab Section: <tuesday, 11:30, SC289>
 * * Description: <determine whether the user input point is in the triangle or the rectangle defined by the x range and the y range of the x values of the triangle. Output whether the point is in any of the range or error messages accordingly>
 * * Programmers: <fullnam login1@purdue.edu>
 * *              <fullname2 login2@purdue.edu>
 * *              <fullname3 login3@purdue.edu>
 * * The person(s) listed above affirm that this is an original work and any
 * * violation of the academic integrity policy will be penalized.
 * ******************************************************************************/
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

// Function Declarations
int inputRandom(int*, int*);
int generateRandom(int lower, int upper);
int findLargest( int, int, int);
int findSmallest( int, int, int);
void inputPoints(int *xPoint, int *yPoint, int smallestX, int largestX, int smallestY, int largestY, int min, int max);
void output( int dX, int dY, int aX, int aY, int bX, int bY, int cX, int cY,double diffA, int min, int max,int tTest);
int tTester(int dX, int dY, int aX, int aY, int bX, int bY, int cX, int cY);
double calcArea(int aX,int aY,int bX,int bY,int cX,int cY,int dX,int dY);


int main()
{
// Local Declarations
  int aX;         // Position x in point a
  int aY;         // Position y in point a
  int bX;         // Position x in point b
  int bY;         // Position y in point b
  int cX;         // Position x in point c
  int cY;         // Position y in point c
  int dX;         // Fourth point position x
  int dY;         // Fourth point position y
  int seed;       // Inputted value of the random seed by the user
  int min = 0;    // Minimum value entered, inital value 0
  int max = 0;    // Maximum value entered, initial value 0
  double diffA;   // Difference in areas of small and large triangles
  int smallestY;  // Smallest Y value in first 3 coordinates
  int smallestX;  // Smallest X value in first 3 coordinates
  int largestY;   // Largest Y value in first 3 coordinates
  int largestX;   // Largest X value in first 3 coordinates
  int tTest;      // 1 if inside triangle, 2 if inside

// Statements

  // Define seed for random numbers
  seed = inputRandom(&min, &max);
  srand(seed);
 
  // Generate 3 sets of (x,y) coordinates based on seed, these points make triangle
  aX = generateRandom(min, max);
  aY = generateRandom(min ,max);
  bX = generateRandom(min, max);
  bY = generateRandom(min, max);
  cX = generateRandom(min, max);
  cY = generateRandom(min, max);
 
  // Find the largest and smallest values of y
  largestX = findLargest(aX, bX, cX);
  smallestX =  findLargest(aY, bY, cY);
  largestY =  findSmallest(aY, bY, cY);
  smallestY =  findSmallest(aX, bX, cX);
   
  // Calculate Difference in Areas between small and large Triangles
  diffA = calcArea(aX, aY, bX, bY, cX, cY, dX, dY);
  
  // Input 4th set of coordinates to test if they are in triangle
  inputPoints(&dX, &dY, smallestX, largestX, smallestY, largestY, min, max);
  tTest =  tTester(dX, dY, aX, aY, bX, bY, cX, cY);
  
  // Output final information
  output(dX, dY,aX, aY, bX, bY, cX, cY, diffA, min, max, tTest);
  
  return 0;
}//end of main


/******************************************************************************
* Function:    <inputRandom>
* Description: <scan the inputs>
* Parameters:  <seed, int, the input seed value for generating random numbers>
*              <min, int, the minimum value generated>
*              <max, int, the maximum value generated>
* Return:      <void>
********************************************************************************/     
int inputRandom(int *min, int *max) 
{
  //local declarations
  int seed; // seed for random generation
  //statements
  printf("Enter seed value for random number generation: ");
  scanf("%d", &seed); //scans for inputted value of entered value
  srand(seed);
  printf("Enter minimum value to generate: ");
  scanf("%d", &*min);
  printf("Enter maximum value to generate: ");
  scanf("%d", &*max);
  if (min >= max)
    printf("Error! Max must be greater than min!");

  return seed;
} // inputRandom

/******************************************************************************
* Function:    <generateRandom>
* Description: <generate random coordinates>
* Parameters:  <lower, int, the lower bound of the generation range (inclusive)>
*              <upper, int, the upper bound of the generation range (inclusive)>
* Return:      <random number, int>
*******************************************************************************/
int generateRandom(int lower, int upper)
{
  int coordinate;
  int range;
  range = upper - lower +1;
  coordinate = rand() % range + lower;
  return coordinate;//returns the value of the coordinates to the main function
} // generateRandom

/******************************************************************************
* Function:    <inputPoints>
* Description: <receives the user's new points(dX,dY)>
* Parameters:  <dX, int by address, x value of point d>
*              <dY, int by address, y value of point d>
* Return:      <void>
*******************************************************************************/

void inputPoints(int *dX, int *dY, int smallestX, int largestX, int smallestY,int largestY, int min, int max)
{
// Statments
  printf("Enter x value in the range [%d, %d]: ", smallestX, largestX);
  scanf("%d", &*dX);
  printf("Enter y value in the range [%d, %d]: ", smallestY, largestY);
  scanf("%d", &*dY);
  return;
} // inputPoints

/******************************************************************************
* Function:    <FindsLargest>
* Description: <returns largest value of three points>
* Parameters:  <p1, int, one of three points to compare>
*              <p2, int, one of three points to compare>
*              <p3, int, one of three points to compare>
* Return:      <int, largest value of the three>
*******************************************************************************/

int findLargest(int p1, int p2, int p3)
{
// Local Declaration
      int largest; // Magnitude of largest point

// Statements
  // Determines which point is largest
  if (( p3 > p2) && (p3 > p1))
    largest = p3;
  if ((p2 > p3) && (p2 > p1))
    largest = p2;
  if ((p1 > p2) && (p1 > p3))
    largest = p1;
  return largest;
} // findLargest

/******************************************************************************
* Function:    <findSmallest>
* Description: <returns smallest value of three points>
* Parameters:  <p1, int, one of three points to compare>
*              <p2, int, one of three points to compare>
*              <p3, int, one of three points to compare>
* Return:      <int, smallest value of the three>
*******************************************************************************/

int findSmallest(int p1, int p2, int p3)
{
// Local Declarations
  int smallest;

// Statements
  // Determines the smallest value of the points
  if (( p3 < p2) && (p3 < p1))
    smallest = p3;
  if ((p2 < p3) && (p2 < p1))
    smallest = p2;
  if ((p1 < p2) && (p1 < p3))
    smallest = p1;
  return smallest;
}

/******************************************************************************
* Function:    <tTester>
* Description: <Calcualtes dot products of the sides of triangle, determines whether a point is within triangle>
* Parameters:  <dX, int, point x value>
*              <dY, int, point y value>
*              <aX, int, point x value>
*              <aY, int, point y value>
*              <bX, int, point x value>
*              <bY, int, point y value>
*              <cX, int, point x value>
*              <cY, int, point y value>
* Return:      <int, true(inside triangle) or false(outside triangle)>
******************************************************************************/

int tTester(int dX, int dY, int aX, int aY, int bX, int bY, int cX, int cY)
{

// Local Declarations
  int dotProd1; // dot product of 2 sides of triangle
  int dotProd2; // dot product of 2 sides of triangle
  int dotProd3; // dot product of 2 sides of triangle
  int insideOutside; // 0 if outside, 1 if inside

// Statements
  // Calculates dot products of each triangle side vector
  dotProd1 = (bY - aY) * (dX - aX) + (aX - bX) * (dY - aY);
  dotProd2 = (cY - bY) * (dX - bX) + (bX - cX) * (dY - bY);
  dotProd3 = (aY - dY) * (dX - cX) + (cX - aX) * (dY - cY);
  
  // Uses dot products to determine if point (dX, dY) is inside the triangle
  if (0 <= dotProd1 && 0 <= dotProd2 && 0 <= dotProd3)
    insideOutside = 1; // inside triangle
  else
    insideOutside = 0; // outside triangle

    return insideOutside; // return true false value
}// tTester

/******************************************************************************
* Function:    <calcArea>
* Description: <brief description of what the function does>
* Parameters:  <variable1 name, data type, and description>
*              <variable2 name, data type, and description>
* Return:      <data type and description>
******************************************************************************/
double calcArea(int aX,int aY,int bX,int bY,int cX,int cY,int dX,int dY)
{
// Local Declarations
  double areaS; // Area small triangle
  double areaL; // Area large triangle
  double diffA; // Difference between areaS and areaL
// Statements
  areaS = 0.5 * abs((aX * (bY - dY)) + (bX * (dY - aY)) + (dX * (aY - bY))); // Calculates area of small triangle
  areaL = 0.5 * abs((aX * (bY - cY)) + (bX * (cY - aY)) + (cX * (aY - bY))); // Calculates area of large triangle
  diffA = abs(areaL - areaS); // finds difference in areas

  return diffA;
}// calcArea

/******************************************************************************
* Function:    <output>
* Description: <print out the results>
* Parameters:  <dX, int, point x value>
*              <dY, int, point y value>
*              <aX, int, point x value>
*              <aY, int, point y value>
*              <bX, int, point x value>
*              <bY, int, point y value>
*              <cX, int, point x value>
*              <cY, int, point y value>
*              <diffA, double, difference bewteen small triangle and large triangle area>
*              <min, int, min input boundry>
*              <max, int, max input boundry>
*              <tTest, int, triangle point test ( inside outside)>
 * * Return:   <void>
 * ******************************************************************************/
void output( int dX, int dY, int aX, int aY, int bX, int bY, int cX, int cY,double diffA, int min, int max,int tTest)
{

// Statements
 {

    printf("Generated Points: (%d, %d), (%d, %d), (%d, %d)\n", aX, aY, bX, bY, cX, cY);
  
  // Inside or Outside Triangle
    if (tTest == 0)
    { 
      printf("The fourth point (%d, %d) is outside the triangle.\n", dX, dY);
      printf("Area difference bewteen larger and smaller triangles: %0.1f\n", diffA);
    }
    else 
    printf("The fourth point (%d, %d) is inside the triangle.\n", dX, dY);
 }

  return;
} // print
