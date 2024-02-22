#include <iostream>
#include <fstream>
using namespace std;
const int nmax = 1000;

int main(){

  ifstream fin("blugi.in");
  ofstream fout("blugi.out");

  unsigned n; fin >> n;
  n++;

  unsigned colection[nmax];
  for(int i = 0; i < n; i++){
    colection[i] = 0;
  }

  for(int i = 0; i < n; i++){
    fin >> colection[i];
  };
  
  for(int i = 0; i < n; i++){
    if(colection[i] == 0){
      fout << i;
    }
  }

  fin.close();
  fout.close();

  return 0;
}