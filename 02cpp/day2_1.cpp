#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){
  vector <string> directions;
  string line;
  int lines;

  cout << "Input line: " << endl;
  while(getline(cin,line)){
    directions.push_back(line.c_str());
    lines++;
    if(cin.peek() == '\n'){
      break;
    }
  }
  for(int i = 0;i < directions.size();i++){
    cout << "LINE: " << i << endl;
    cout << directions[i] << endl;
  }
//make a numpad grid

vector < vector<int> > grid(3, vector<int>(3,1));
vector < vector<bool> > cursorGrid(3, vector<bool>(3,0));
int currentY = 1;
int currentX = 1;
cursorGrid[currentY][currentX] = 1;

for(int y = 0;y < 3; y++){
  for(int x = 0;x < 3;x++){
    grid[y][x] += y*3 + x;
    cout << grid[y][x];
  }
  cout << endl;
}
cout << "test" << endl;
cout << directions[0][2] << endl;
cout << directions.size() << endl;
cout << directions[0][10] << endl;

for(int i = 0;i < directions.size();i++){
  for(int j = 0;j < directions[i].size();j++){
    switch(directions[i][j]){
      case 'U':
        if(currentY > 0){
        cursorGrid[currentY][currentX] = 0;
        currentY--;
        cursorGrid[currentY][currentX] = 1;
        break;
      }
        else{
          break;
        }
      case 'D':
        if(currentY < 2){
          cursorGrid[currentY][currentX] = 0;
          currentY++;
          cursorGrid[currentY][currentX] = 1;
          break;
        }
        else{
        break;
          }
      case 'R':
        if(currentX < 2){
          cursorGrid[currentY][currentX] = 0;
          currentX++;
          cursorGrid[currentY][currentX] = 1;
          break;
        }
        else{
            break;
          }
      case 'L':
        if(currentX > 0){
          cursorGrid[currentY][currentX] = 0;
          currentX--;
          cursorGrid[currentY][currentX] = 1;
          break;
        }
        else{
            break;
          }
    }
  }
  cout << endl;
  cout << "Current Y: " << currentY << " " << "Current X: " << currentX << endl;
  cout << "Code: " << grid[currentY][currentX] << endl;
}



  return 0;
}
