#include <iostream>

int row = 8000;
int col = 8000;
int maxW = 32000;
int maxH = 32000;
int nCounter = 0;

bool SeAflaIn(int a, int b, int c, int d){
  nCounter++;
  if(a <= col && b <= row && c >= col && d >= row) return true;
  else return false;
}
int maxWidth(){
  return maxW;
}
int maxHeight(){
  return maxH;
}
void Coordonatele(int i, int j){
  if(col == i && row == j){
    std::cout << "Ai ghicit! (" << nCounter << " intrebari)";
  }
  else{
    std::cout << "Nu ai ghicit... (" << nCounter << " intrebari)";
  }
}