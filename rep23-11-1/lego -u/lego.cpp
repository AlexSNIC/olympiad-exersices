#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int main(){

  ifstream fin("lego.in");
  ofstream fout("lego.out");

  int a1, a2, a3, b1, b2, b3;
  long k;
  fin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> k;

  while(true){
    if(!(b1 || b2 || b3)) break;
    if(k == 0) break;
    
  }

  fin.close();
  fout.close();

  return 0;
}