#include <iostream>
#include <fstream>
using namespace std;


int main(){

  ifstream fin("maxprod.in");
  ofstream fout("maxprod.out");

  int n; fin >> n;
  int max1 = INT_MIN, 
      max2 = INT_MIN, 
      min1 = INT_MAX, 
      min2 = INT_MAX;
  long totalMax;
  for(int i = 0; i < n; i++){
    int val; fin >> val;

    if(max1 < val) max1 = val;
    else if(max2 < val) max2 = val;

    if(min1 > val) min1 = val;
    else if(min2 > val) min2 = val;
  }
  totalMax = max(max1 * max2, min1 * min2);
  fout << totalMax;

  fin.close();
  fout.close();  

  return 0;
}