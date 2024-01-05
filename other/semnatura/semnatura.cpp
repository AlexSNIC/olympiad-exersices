#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main(){

  ifstream fin("semnatura.in");
  ofstream fout("semnatura.out");

  int q; fin >> q;
  string s; fin >> s;

  int n = q;
  for(int i = 0; i < s.length(); i++){
    n += (i + 1) * pow(s[i], 3);
  }

  fout << n;

  fin.close();
  fout.close();

  return 0;
}