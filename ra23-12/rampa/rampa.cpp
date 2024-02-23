#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

int maxRamp = 0, nMax = 0;
void findRamp(vector<int>& vec, int index, vector<int>& ramp, int skip){
  const int vecSize = vec.size();
  if(vecSize - index < maxRamp)return;
  for(int i = index; i < vecSize; i++){
    
    ramp.push_back(vec.at(i));
    sort(ramp.begin(), ramp.end());

    bool isValid = true;
    for(int i = 0; i < ramp.size() - 1; i++){
      if(ramp.at(i) + 1 != ramp.at(i + 1))
        isValid = false;
      if(!isValid) break;
    }
    if(isValid){
      int size = i - index + 1;
      if(maxRamp < size){
        maxRamp = size;
        nMax = 1;
        skip = size;
      }
      else if(maxRamp == size && !skip){
        nMax++;
        skip = size;
      }
    }
  }
  ramp.clear();
  if(skip != 0) skip--;
  findRamp(vec, index + 1, ramp, skip);
}

int main(){

  ifstream fin("rampa.in");
  ofstream fout("rampa.out");
  
  int n; fin >> n;
  int temp;
  vector<int> vec;
  while(fin >> temp){
    vec.push_back(temp);
  }
  vector<int> ramp;
  findRamp(vec, 0, ramp, 0);

  fout << maxRamp << endl << nMax;


  fin.close();
  fout.close();

  return 0;
}