#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void print(vector<short> vec){
  for(int val : vec){
    cout << val << " ";
  }
  cout << endl;
}
int findTime(vector<short>& pieces, vector<short>& strungs){
  if(pieces.empty()){
    int maxVal = 0;
    for(int val : strungs){
        maxVal = max(maxVal, val);
    }
    return maxVal;
  }
  for(short& strung : strungs){
    strung--;
    if(strung == 0 && !pieces.empty()){
      strung = pieces.back();
      pieces.pop_back();
    }
  }
  return 1 + findTime(pieces, strungs);
}

int main(){ 
  ifstream fin("strung.in");
  ofstream fout("strung.out");

  int size, nStrungs;
  fin >> nStrungs >> size;
  vector<short> pieces;
  vector<short> strungs(nStrungs, 1);
  short temp;
  while(fin >> temp) 
    pieces.push_back(temp);

  int time = findTime(pieces, strungs);
  cout << time;
  fin.close();
  fout.close();
  return 0;
}