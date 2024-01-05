#include <iostream>
#include <fstream>
using namespace std;


int main(){

  ifstream fin("inscriptie.in");
  ofstream fout("inscriptie.out");

  int n; fin >> n;
  int colection[n];

  for(int i = 0; i < n; i++){
    if(i < (n + 1)/ 2){
      colection[i] = 2 * i + 1;
    }
    else colection[i] = (n - i) * 2;
  }
  for(int i = 0; i < n; i++){
    fout << colection[i] << ' ';
  }


  fin.close();
  fout.close();

  return 0;
}