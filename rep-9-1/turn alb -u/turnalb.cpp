#include <iostream>
#include <fstream>

using namespace std;

short mat[9][9];


int letterToNr(char letter){
  return letter - 96;
}
int stringToNr(char nr){
  return nr - 48;
}

int main(){

  ifstream fin("turnalb.in");
  ofstream fout("turnalb.out");
  

  fin.close();
  fout.close();

  return 0;
}