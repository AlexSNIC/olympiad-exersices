#include <iostream>
#include <fstream>
using namespace std;

const int nmax = 30;

int mat[nmax][nmax];

int calc(int x, int y){
  if(x < 0) return 0;
  if(x > y) return 0;

  if(mat[x][y] != 0) return mat[x][y];
  if(x == 0) {
    mat[x][y] = 1;
    return 1;
  }
  if(x == y) {
    mat[x][y] = 1;
    return 1;
  }

  mat[x][y] = calc(x, y - 1) + calc(x - 1, y - 1);
  return mat[x][y];
}

int main(){

  ifstream fin("triunghi.in");
  ofstream fout("triunghi.out");

  int n; fin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      mat[i][j] = 0;

  mat[0][0] = 1;
  for(int i = 0; i < n; i++){
    fout << calc(i, n - 1) << " ";
  }



  fin.close();
  fout.close();

  return 0;
}