#include <iostream>
#include <fstream>
#include <vector>
#define nmax 2000
using namespace std;

char mat[nmax][nmax];

int diamonds = 0;
void printMat(int dimX, int dimY){
  for(int i = 0; i < dimY; i++){
    for(int j = 0; j < dimX; j++){
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}
bool isDiamondEmpty(int tipX, int tipY, int k){
  return true;
}

void findDiamond(int tipX, int tipY, int dimX, int dimY, int k){
  bool isDiamond = true;

  for(int i = 1; i <= k; i++){
    if(tipY + k + i >= dimY || tipX - k + i < 0){
      isDiamond = false;
      break;
    }
    if(mat[tipY + k + i][tipX - k + i] != '#')isDiamond = false;
  }

  for(int i = 0; i <= k; i++){
    if(tipY +  2*k - i >= dimY || tipX + i >= dimX){
      isDiamond = false;
      break;
    }
    if(mat[tipY +  2*k - i][tipX + i] != '#')isDiamond = false;
  }

  for(int i = 0; i <= k; i++){
    if(tipY + k - i >= dimY || tipX + k - i >= dimX){
      isDiamond = false;
      break;
    }
    if(mat[tipY + k - i][tipX + k - i] != '#')isDiamond = false;
  }
  

  if(isDiamond){ 
    if(isDiamondEmpty(tipX, tipY, k))
      diamonds++;
  }
  else if(tipY + k - 1 < dimY && tipX - k - 1 > 0)
    if(mat[tipY + k - 1][tipX - k - 1] == '#')
      findDiamond(tipX, tipY, dimX, dimY, k + 1);
}

void findTip(int x, int y, int dimX, int dimY){
  if(x >= dimX) {
    findTip(0, y + 1, dimX, dimY);
    return;
  }
  if(y >= dimY) return;
  

  if(mat[y][x] == '#') findDiamond(x, y, dimX, dimY, 1);
  findTip(x + 1, y, dimX, dimY);
}



int main(){

  ifstream fin("diamant.in");
  ofstream fout("diamant.out");

  int dimX, dimY;
  fin >> dimY >> dimX;

  for(int i = 0; i < dimY; i++){
    for(int j = 0; j < dimX; j++){
      fin >> mat[i][j];
    }
  }
  findTip(0, 0, dimX, dimY);

  cout << diamonds;

  fin.close();
  fout.close();

  return 0;
}