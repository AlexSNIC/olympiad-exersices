#include <iostream>
#include <fstream>
#define nmax 500000
using namespace std;

long p[nmax];

void quickSort(int start, int end){
  if(end <= start) return;
  int i = start - 1;

  for(int j = start; j < end; j++)
    if(p[j] < p[end])
      swap(p[++i], p[j]);
  swap(p[++i], p[end]);

  quickSort(start, i - 1);
  quickSort(i + 1, end);
}


int main(){

  ifstream fin("turneu.in");
  ofstream fout("turneu.out");

  int n;
  fin >> n;
  long sumF = 0;

  for(int i = 0; i < n; i++){
    int fn;
    fin >> p[i] >> fn;
    sumF += fn;
  }
  quickSort(0, n - 1);

  long minDelta = LNG_MAX;
  for(int i = 0; i < n - 1; i++){
    int delta = p[i + 1] - p[i];
    if(delta < minDelta){

    }
  }


  fin.close();
  fout.close();

  return 0;
}