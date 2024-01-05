#include <iostream>
#include <fstream>
using namespace std;


int main(){

  ifstream fin("indburs.in");
  ofstream fout("indburs.out");

  int n; fin >> n;
  int collection[n];
  for(int i = 0; i < n; i++){
    fin >> collection[i];
  }
  int act; fin >> act;
  int sum = 0;
  for(int i = n; i >= act; i--){
    for(int j = 0; j < i - 1; j++){
      if(collection[j + 1] > collection[j]){
        if(collection[j] < collection[j + 1]){
          collection[j] ^= collection[j + 1] ^= collection[j] ^= collection[j + 1];
        }
      }
    }
    sum += collection[i - 1];
  }

  fout << sum;

  fin.close();
  fout.close();

  return 0;
}