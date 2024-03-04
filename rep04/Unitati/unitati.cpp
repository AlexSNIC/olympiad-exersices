#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int findN(vector<int>& vec, int n){
  if(n == 1) return 2;
  if(n == 2) return 3;

  if(vec.at(n) == -1) vec.at(n) = findN(vec, n - 1) + findN(vec, n - 2);
  return vec.at(n);
}

int main(){
  ifstream fin("unitati.in");
  ofstream fout("unitati.out");
  int n; fin >> n; 
  vector<int> vals(n + 1, -1);
  fout << findN(vals, 100);
  

  fin.close();
  fout.close();
}