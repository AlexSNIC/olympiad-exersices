#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
int charToInt(char c){
  return c - '0';
}

int findMatch(bool higher, int nr, int target){
  if(higher)
    for(int i = 9; i > target; i--){
      int val = nr + i;
      if(val % 3 == 0) return i;
    }
  else
    for(int i = target - 1; i >= 0; i--){
      int val = nr + i;
      if(val % 3 == 0) return i;
    }
  return -1;
}

int nrIndex{}, nrValue{};

void findNr(string& nrStr, int index, int nr, bool higher){
  int target = charToInt(nrStr[index]);
  
  int val = findMatch(higher, nr - target, target);
  if(val != -1){
    nrIndex = index;
    nrValue = val;
    return;
  }
  if((index == nrStr.length() - 1) && higher)
    findNr(nrStr, index, nr, false);
  else{
    findNr(nrStr, (higher? index + 1 : index - 1), nr, higher);
  }
  
}

int main(){
  ifstream fin("numere.in");
  ofstream fout("numere.out");

  string nr; fin >> nr;

  int reduced {};

  for(char c : nr){
    reduced += charToInt(c);
  }
  findNr(nr, 0, reduced, true);

  nr[nrIndex] = char(nrValue + '0');
  fout << nr;

  fin.close();
  fout.close();
}