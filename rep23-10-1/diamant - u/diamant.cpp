#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

  ifstream fin("diamant.in");
  ofstream fout("diamant.out");

  int sizeX, sizeY;
  fin >> sizeY >> sizeX;
  vector<vector<bool>> mat(sizeY, vector<bool>(sizeX, 0));

  for(vector<bool>& vec : mat){
    for(bool val : vec){
      val = 1;
    }
  }
  cout << mat.at(0).at(0);

  fin.close();
  fout.close();

  return 0;
}