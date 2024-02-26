#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int satisfaction(vector<int>& loc, int k, int ut, int ua){
  if(k >= loc.size()) return 0;
  int sum = 0;
  
}

int main(){

  ifstream fin("file.in");
  ofstream fout("file.out");
  
  int n, ut, ua;  
  fin >> n >> ut >> ua;
  int temp;
  vector<int> loc;
  while(fin >> temp){
    loc.push_back(temp);
  }

  

  fin.close();
  fout.close();

  return 0;
}