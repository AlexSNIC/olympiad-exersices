#include <iostream>
#include <fstream>
using namespace std;


int main(){
  ifstream fin("concursuri.in");
  ofstream fout("concursuri.out");

  int n, p; fin >> n >> p;
  int comp[n];

  for(int i = 0; i < n; i++){
    fin >> comp[i];
  }

  int delta[n-1];
  for(int i = 0; i < n - 1; i++){
    delta[i] = comp[i + 1] - comp[i] - 1;
  }
  for(int i = 0; i < p - 1; i++){
    int max = INT_MIN, maxPoz;
    for(int j = 0; j < n-1; j++){
      if(max < delta[j]){
        max = delta[j];
        maxPoz = j;
      }
    }
    delta[maxPoz] = 0;
  }
  int sum = 0;
  for(int i = 0; i < n - 1; i++){
    sum += delta[i];
  }
  sum += n;
  fout << sum;

  fin.close();
  fout.close();
  return 0;
}