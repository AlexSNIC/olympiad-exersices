#include <iostream>
#include <fstream>
#define nmax 100
using namespace std;

short dimX, dimY;
short mat[nmax][nmax];
short prices[nmax];

short maxPeeps = SHRT_MIN;
short maxPeepsPath[nmax][2];
short maxPeepsPathLength;

short mtArr[nmax][2];

void nPeeps(int x, int y, int peeps, int peepsPath[nmax][2], int peepsPathLength){
  peeps += mat[y][x];
  peepsPath[peepsPathLength][0] = x;
  peepsPath[peepsPathLength][1] = y;
  peepsPathLength++;

  if(x - 1 >= 0 && y + 1 < dimY){
    if(mat[y + 1][x - 1] != 0)
      nPeeps(x - 1, y + 1, peeps, peepsPath, peepsPathLength);;
  }
  else if(y + 1 < dimY){
    if(mat[y + 1][x + 1] != 0)
      nPeeps(x, y + 1, peeps, peepsPath, peepsPathLength);
  }
  else if(x + 1 < dimX && y + 1 < dimY){
    if(mat[y + 1][x + 1] != 0)
      nPeeps(x + 1, y + 1, peeps, peepsPath, peepsPathLength);
  }
  else if(peeps > maxPeeps){
    maxPeeps = peeps;
    maxPeepsPathLength = peepsPathLength;
    for(int i = 0; i < peepsPathLength; i++){
      maxPeepsPath[i][0] = peepsPath[i][0];
      maxPeepsPath[i][1] = peepsPath[i][1];
    }
  }
}


int main(){

  ifstream fin("hotel.in");
  ofstream fout("hotel.out");

  fin >> dimY >> dimX;
  for(int i = 0; i < dimY; i++){
    for(int j = 0; j < dimX; j++){
      fin >> mat[i][j];
    }
  }
  for(int i = 0; i < dimY; i++){
    if(mat[0][i] != 0) nPeeps(i, 0, 0, mtArr, 0);
  }
  cout << maxPeeps;

  fin.close();
  fout.close();

  return 0;
}