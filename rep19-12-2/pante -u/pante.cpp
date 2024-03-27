#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int getMod(long long n){
  return n % (int)(1e9 + 7);
}


int main(){

  ifstream fin("pante.in");
  ofstream fout("pante.out");
  
  string a; string b;
  fin >> a >> b;
  

  fin.close();
  fout.close();

  return 0;
}