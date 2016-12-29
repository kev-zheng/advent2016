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

vector < vector<char> > grid(5, vector<char>(5,'.'));
grid[0][2] = '1';

grid[1][1] = '2';
grid[1][2] = '3';
grid[1][3] = '4';

for(int i = 0;i < 5;i++){
  grid[2][i] = '0' + i + 5;
}

grid[3][1] = 'A';
grid[3][2] = 'B';
grid[3][3] = 'C';

grid[4][2] = 'D';


vector < vector<bool> > cursorGrid(5, vector<bool>(5,0));
int currentY = 2;
int currentX = 0;
cursorGrid[currentY][currentX] = 1;
cout << "printing grid: " << endl;
for(int y = 0;y < 5; y++){
  for(int x = 0;x < 5;x++){
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
          currentY--;
          if(grid[currentY][currentX] == '.'){
            currentY++;
            break;
          }
        break;
      }
        else{
          break;
        }
      case 'D':
        if(currentY < 4){
          currentY++;
          if(grid[currentY][currentX] == '.'){
            currentY--;
            break;
          }
        break;
      }
        else{
          break;
        }
      case 'R':
        if(currentX < 4){
          currentX++;
          if(grid[currentY][currentX] == '.'){
            currentX--;
            break;
          }
        break;
      }
        else{
          break;
        }
      case 'L':
        if(currentX > 0){
          currentX--;
          if(grid[currentY][currentX] == '.'){
            currentX++;
            break;
          }
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
