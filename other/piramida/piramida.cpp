#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main(){

  ifstream fin("piramida.in");
  ofstream fout("piramida.out");

  int n; fin >> n;
  int nr; fin >> nr;
  bool is_even = n%2 == 1;

  int colection[n];
  for(int i = n - 1; i >= 0; i--){
    colection[i] = nr%10;
    nr/=10;
  }

  for(int i = 0; i < n/2 + is_even; i++){
    fout << setw(n/2 - i + is_even);
    for(int k = n/2 - i - !is_even; k < n/2 + i + 1; k++){
      fout << colection[k];
    }
    fout << endl;
  }

  

  fin.close();
  fout.close();

  return 0;
}