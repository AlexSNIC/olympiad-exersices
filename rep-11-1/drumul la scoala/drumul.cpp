#include <iostream>
#include <fstream>
#define nmax 1000
using namespace std;

char table[nmax][nmax];
int dimX, dimY, cX, cY, sX, sY;

long long minPath = INT_MAX;
long long paths = 0;
void findPath(int x, int y, int count){
  if(x < 0 || x >= dimX) return;
  if(y < 0 || y >= dimY) return;
  if(table[y][x] == 'X') return;
  
  count++;
  if(x == sX && y == sY){
    if(count < minPath){
      paths = 1;
      minPath = count;
    }
    else if(minPath == count) paths++;
    return;
  }
  table[y][x] = 'X';
  findPath(x + 1, y, count);
  findPath(x, y + 1, count);
  findPath(x - 1, y, count);
  findPath(x, y - 1, count);
  table[y][x] = '.';
}

int main(){

  ifstream fin("drumul.in");
  ofstream fout("drumul.out");
  fin >> dimY >> dimX >> cY >> cX >> sY >> sX; 
  cX--; cY--; sX--; sY--;
  for(int i = 0; i < dimY; i++){
    fin >> table[i];
  }

  findPath(0, 0, 0);

  fout << minPath << " " << paths;


  fin.close();
  fout.close();

  return 0;
}