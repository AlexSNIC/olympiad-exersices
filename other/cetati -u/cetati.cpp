#include <iostream>
#include <fstream>
using namespace std;

struct Cetate{
  int x, y;
}

int main(){

  ifstream fin("cetati.in");
  ofstream fout("cetati.out");

  int n; fin >> n;
  Cetate cetati[n];

  for(int i = 0; i < n; i++){
    fin >> cetati[i].x >> cetati[i].y;
  }
  


  fin.close();
  fout.close();

  return 0;
}