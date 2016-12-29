#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
ifstream inFile("day4_1.txt");

string line;
string checksum;
string decrypted;

int sectorID, maxNum, maxChar;
long long int totalID = 0;
int array[255] = {0};
bool isDecoy;

while(inFile >> line){
  fill(array,array + 255,0);
  checksum = line.substr(line.find('[')+1,5);
  sectorID = stoi(line.substr(line.find('[')-3,3));
  for(int i = 0;i < line.size() - 11;i++){
    ++array[line[i]];
  }
  for(int i = 0;i < 5;i++){
    isDecoy = 0;
    maxNum = 0;
    for(int j = 97;j <= 122;j++){
      if(array[j] > maxNum){
        maxNum = array[j];
        maxChar = j;
      }
      }
      if(static_cast<char>(maxChar) != checksum[i]){
        isDecoy = 1;
        break;
      }
      array[maxChar] = 0;
    }
  if(!isDecoy){
    decrypted.erase(decrypted.begin(),decrypted.end());
    for(int i = 0;i < line.size()-11;i++){
      if(line[i] != '-'){
      decrypted.push_back((((int(line[i]) - 97) + sectorID%26)%26) + 97);
    }
    else{
      decrypted.push_back(' ');
    }
    }
    if(decrypted.find("northpole") != decrypted.npos){
      cout << decrypted << endl;
      cout << sectorID << endl;
    }
}
}
return 0;
}
