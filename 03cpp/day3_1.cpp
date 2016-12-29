#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool isTriangle(int a,int b, int c){
  int bigSide, smallSides;
  bigSide = max(a,b);
  bigSide = max(bigSide,c);
  smallSides = a + b + c - bigSide;
  return(smallSides > bigSide);
}

int main(){

  ifstream inFile("day3_2.txt");
  int a, b, c, bigSide, smallSides;
  int validTriangles = 0;
  int grid[3][3];
  while(inFile >> grid[0][0] >> grid[0][1] >> grid[0][2]
               >> grid[1][0] >> grid[1][1] >> grid[1][2]
               >> grid[2][0] >> grid[2][1] >> grid[2][2]){
    for(int i = 0;i < 3;i++){
      if(isTriangle(grid[0][i],grid[1][i],grid[2][i])){
        validTriangles++;
      }
    }
    }
  cout << "There are " << validTriangles << " valid triangles." << endl;
  return 0;

}
