#include <iostream>
#include <fstream>
#define nmax 30000

using namespace std;
int collection[nmax];

int maxArea = INT_MIN;

int findWidth(int x, int n){
  int sum = 0;
  for(int i = x; i >= 0; i--){
    if(collection[x] > collection[i])break;
    sum++;
  }
  for(int i = x; i < n; i++){
    if(collection[x] > collection[i])break;
    sum++;
  }
  return sum - 1;
}

void calcMax(int x, int n){
  if(x >= n)return;

  int width = findWidth(x, n);
  int area = width * collection[x];
  maxArea = max(area, maxArea);

  calcMax(x + 1, n);
}

int main(){

  ifstream fin("histograma.in");
  ofstream fout("histograma.out");

  int n; fin >> n;
  for(int i = 0; i < n; i++){
    fin >> collection[i];
  }
  calcMax(0, n);
  fout << maxArea;

  fin.close();
  fout.close();

  return 0;
}