#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool mat[40][40];
int minCount = INT_MAX;

void findPoz(int x, int y, int finX, int finY, int sizeX, int sizeY, int count){
  if(x < 0 || x >= sizeX) return;
  if(y < 0 || y >= sizeY) return;
  if(mat[y][x] == 1) return;
  if(x == finX && y == finY){
    minCount = count < minCount? count : minCount;
    return;
  }
  count++;
  mat[y][x] = 1;

  findPoz(x + 1, y, finX, finY, sizeX, sizeY, count);
  findPoz(x - 1, y, finX, finY, sizeX, sizeY, count);
  findPoz(x, y + 1, finX, finY, sizeX, sizeY, count);
  findPoz(x, y - 1, finX, finY, sizeX, sizeY, count);

  mat[y][x] = 0;

}

int main(){

  ifstream fin("roboti.in");
  ofstream fout("roboti.out");

  int sizeX, sizeY;
  fin >> sizeY >> sizeX;

  int robotPozX = -1, robotPozY, finPozX, finPozY;

  for(int i = 0; i < sizeY; i++){
    for(int j = 0; j < sizeX; j++){
      int x;
      fin >> x;
      if(x == 2){
        if(robotPozX == -1){
          robotPozX = j;
          robotPozY = i;
        }
        else{
          finPozX = j;
          finPozY = i;
        }
        mat[i][j] = 0;
      }
      else mat[i][j] = x;
    }
  }
  findPoz(robotPozX, robotPozY, finPozX, finPozY, sizeX, sizeY, 0);

  fout << ceil(minCount / 2.0 );
  fin.close();
  fout.close();

  return 0;
}