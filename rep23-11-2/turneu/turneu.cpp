#include <iostream>
#include <fstream>
#include <climits>

#define nmax 500000
using namespace std;

long pw[nmax];
int fm[nmax];

void quickSort(int start, int end){
  if(end <= start) return;
  int i = start - 1;

  for(int j = start; j < end; j++)
    if(pw[j] < pw[end]){
      swap(pw[++i], pw[j]);
      swap(fm[i], fm[j]);
    }
  swap(pw[++i], pw[end]);
  swap(fm[i], fm[end]);

  quickSort(start, i - 1);
  quickSort(i + 1, end);
}



int main(){

  ifstream fin("turneu.in");
  ofstream fout("turneu.out");

  int n;
  fin >> n;

  for(int i = 0; i < n; i++){
    fin >> pw[i] >> fm[i];
  }
  quickSort(0, n - 1);

  long maxNum = LONG_MIN;
  for(int i = 0; i < n - 1; i++){
    long num = fm[i] + fm[i + 1] - max(pw[i], pw[i + 1]) + min(pw[i], pw[i + 1]);
    maxNum = max(num, maxNum);
  }

  cout << maxNum;


  fin.close();
  fout.close();

  return 0;
}