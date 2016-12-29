#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cmath>

using namespace std;

int main(){

string instructions;
vector <char> directions;
vector <int> distances;
int currentX = 0;
int currentY = 0;
int currentDirection = 1;
int distance;
int totalDistance;
int posX = 1000;
int posY = 1000;
int bunnyDistance;

cout << "Enter data: " << endl;
while(cin >> instructions){
  if(instructions[instructions.size()] == ','){
  instructions.pop_back();
}
  directions.push_back(instructions[0]);
  instructions.erase(0,1);
  distances.push_back(atoi(instructions.c_str()));
  if(cin.peek() == '\n'){
    break;
  }
}


vector <int> gridLine(2000,0);
vector < vector <int> > grid;
for(int i = 0;i < 2000;i++){
  grid.push_back(gridLine);
}
grid[posX][posY] = 1;

for(int i = 0;i < directions.size();i++){
  if(directions[i] == 'L'){
    currentDirection += 1;
    currentDirection %= 4;
  }
  else if(directions[i] == 'R'){
    currentDirection += 3;
    currentDirection %= 4;
  }
  switch(currentDirection){
    case 0:
      currentX += distances[i];
      for(int d = 0;d < distances[i];d++){
        posX++;
        grid[posX][posY] += 1;
        if(grid[posX][posY] == 2){
          cout << "crossed " << posX << " " << posY << endl;
          bunnyDistance = abs(posX - 1000) + abs(posY - 1000);
          cout << bunnyDistance << endl;
          break;
      }
    }
      break;
    case 1:
      currentY += distances[i];
      for(int d = 0;d < distances[i];d++){
        posY++;
        grid[posX][posY] += 1;
        if(grid[posX][posY] == 2){
          cout << "crossed " << posX << " " << posY << endl;
          bunnyDistance = abs(posX - 1000) + abs(posY - 1000);
          cout << bunnyDistance << endl;
          break;
      }
    }
      break;
    case 2:
      currentX -= distances[i];
      for(int d = 0;d < distances[i];d++){
        posX--;
        grid[posX][posY] += 1;
        if(grid[posX][posY] == 2){
          cout << "crossed " << posX << " " << posY << endl;
          bunnyDistance = abs(posX - 1000) + abs(posY - 1000);
          cout << bunnyDistance << endl;
          break;
      }
    }
      break;
    case 3:
      currentY -= distances[i];
      for(int d = 0;d < distances[i];d++){
        posY--;
        grid[posX][posY] += 1;
        if(grid[posX][posY] == 2){
          cout << "crossed " << posX << " " << posY << endl;
          bunnyDistance = abs(posX - 1000) + abs(posY - 1000);
          cout << bunnyDistance << endl;
          break;
      }
    }
    break;
  }
  cout << "X: " << posX << endl;
  cout << "Y: " << posY << endl;

  }

totalDistance = abs(currentX) + abs(currentY);
cout << "Total Distance: " << totalDistance << " blocks away." << endl;
cout << "Bunny HQ: " << bunnyDistance << " blocks away. " << endl;
  return 0;
}
