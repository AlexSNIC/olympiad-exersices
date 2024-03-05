#include <iostream>

#include "Padure.h"
// maxWidth() - returneaza dimensiunea Ox
// maxHeight() - returneaza dimensiunea Oy
// SeAflaIn(int a, int b, int c, int d) - conform ipotezei
// Coordonatele(int i, int j) - conform ipotezei

using namespace std;

int getRow(int minY, int maxY, int sizeX){
  cout << minY << " " << maxY << endl;
  if(maxY <= minY){
    return maxY;
  }
  int middle = (minY + maxY) / 2;
  bool isLeft = SeAflaIn(0, minY, sizeX, middle);
  if(isLeft)
    return getRow(minY, middle, sizeX);
  else return getRow(middle + 1, maxY, sizeX);
}
int getCol(int minX, int maxX, int sizeY){
  if(maxX <= minX){
    return maxX;
  }
  int middle = (minX + maxX) / 2;
  bool isLeft = SeAflaIn(minX, 0, middle, sizeY);
  if(isLeft)
    return getCol(minX, middle, sizeY);
  else return getCol(middle + 1, maxX, sizeY);
}

int main(){
  int sizeX = maxWidth();
  int sizeY = maxHeight();

  int row = getRow(0, sizeY, sizeX);
  int col = getCol(0, sizeX, sizeY);
  Coordonatele(col, row);
}