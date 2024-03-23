#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
  ifstream fin("ursul.in");
  ofstream fout("ursul.out");

  int n, s; fin >> n >> s;

  vector<vector<int>> mat(n, vector<int>(n));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      char c; fin >> c;

      
    }
  }


  fin.close();
  fout.close();
}