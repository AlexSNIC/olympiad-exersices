#include <iostream>
#include <fstream>
#define nmax 10000
using namespace std;


int main(){

  ifstream fin("poster.in");
  ofstream fout("poster.out");

  char str[nmax];
  fin >> str;
  
  


  fin.close();
  fout.close();

  return 0;
}