#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

const int unset = INT_MAX;

int main(){

  ifstream fin("bare.in");
  ofstream fout("bare.out");
  
  int length, temp; fin >> length >> temp;
  vector<int> dim;
  while(fin >> temp) dim.push_back(temp);


  while(true){
    int minRemainder = unset;
    int minVal;
    for(int val : dim){
      int rem = length % val;
      if(rem <= minRemainder) {
        minVal = val;
        minRemainder = rem;
      }
    }
    if(length - minVal < 0) break;
    length -= minVal;
    if(!length) break; 
  }

  fout << length;

  fin.close();
  fout.close();

  return 0;
}