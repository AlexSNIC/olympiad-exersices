#include <iostream>
#include <fstream>
using namespace std;


int main(){

  ifstream fin("pietoni.in");
  ofstream fout("pietoni.out");
  
  int dimX, dimY, k;
  fin >> dimY >> dimX >> k;
  int dimXS = dimX - k + 1;
  int dimYS = dimY - k + 1;

  int mat[dimY][dimX];
  int sums[dimYS][dimXS];

  for(int i = 0; i < dimY; i++){
    for(int j = 0; j < dimX; j++){
      fin >> mat[i][j];
    }
  }
  for(int i = 0; i < dimYS; i++){
    for(int j = 0; j < dimXS; j++){
      int sum = 0;
      for(int I = 0; I < k; I++){
        for(int J = 0; J < k; J++){
          sum += mat[i + I][j + J];
        }
      }
      sums[i][j] = sum;
    }
  }
  int max = INT_MIN;
  for(int i = 0; i < dimYS; i++){
    for(int j = 0; j < dimXS; j++){
      if(sums[i][j] > max){
        max = sums[i][j];
      }
    }
  }

  bool exitLoop = false;
  int x, y;
  for(int j = 0; j < dimXS; j++){
    for(int i = 0; i < dimYS; i++){
      if(sums[i][j] == max){
        x = j + 1;
        y = i + 1;
        exitLoop = true;
        break;
      }
    }
    if(exitLoop) break;
  }
  fout << max << endl;
  fout << y << " " << x;

  fin.close();
  fout.close();

  return 0;
}