#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

  ifstream fin("numar.in");
  ofstream fout("numar.out");

  string nr; fin >> nr;
  int nrLen = nr.length();
  int index, nrVal = -1;
  for(int i = 0; i < nrLen - 1; i++){
    if(nr[i] <= nr[i + 1]){
      nrVal = nr[i] - 48;
      index = nrLen - i - 1;
      if(nr[i] < nr[i + 1]) break;
    }
  }
  cout << index << " " << nrVal;


  fin.close();
  fout.close();
  return 0;
}