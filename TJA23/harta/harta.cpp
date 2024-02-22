#include <iostream>
#include <fstream>

#define maxSize 100

using namespace std;

bool map[maxSize][maxSize];
int maxSurface = 0;
int currentSurface = 0;
void calcIsland(int x, int y, int sizeX, int sizeY){
  if(x >= sizeX || x < 0)
    return;
  if(y>= sizeY || y < 0)
    return;

  if(map[y][x] == 1){
    currentSurface++;
    maxSurface = max(currentSurface, maxSurface);
    map[y][x] = 0;
  }
  else return;
  calcIsland(x + 1, y, sizeX, sizeY);
  calcIsland(x - 1, y, sizeX, sizeY);
  calcIsland(x, y + 1, sizeX, sizeY);
  calcIsland(x, y - 1, sizeX, sizeY);
}

void findIsland(int x, int y, int sizeX, int sizeY){
  if(x >= sizeX){
    findIsland(0, y+1, sizeX, sizeY);
    return;
  }
  if(y >= sizeY){
    return;
  }

  if(map[y][x] == 1){
    calcIsland(x, y, sizeX, sizeY);
    currentSurface = 0;
  }
  findIsland(x + 1, y, sizeX, sizeY);
}

int main(){
  ifstream fin("harta.in");
  ofstream fout("harta.out");

  int sizeX, sizeY;
  fin >> sizeY >> sizeX;

  for(int i = 0; i < sizeY; i++){
    for(int j = 0; j < sizeX; j++){
      fin >> map[i][j];
    }
  }

  findIsland(0, 0, sizeX, sizeY);

  fout << maxSurface;

  fin.close();
  fout.close();
  return 0;
}