#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

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

for(int j = 0;j < directions.size();j++){
  cout << "Direction: " << directions[j] << endl;
  cout << "Distance: " << distances[j] << endl;
}

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
      break;
    case 1:
      currentY += distances[i];
      break;
    case 2:
      currentX -= distances[i];
      break;
    case 3:
      currentY -= distances[i];
    break;
  }
}
totalDistance = currentX + currentY;
cout << "Total Distance: " << totalDistance << " blocks away." << endl;
  return 0;
}
