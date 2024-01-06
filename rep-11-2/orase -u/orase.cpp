#include <iostream>
#include <fstream>
#include <climits>
#define nmax 200000

using namespace std;

int collection[nmax];
int k, trS, aS;
long maxSatisf = LONG_MIN;

void find(int x, long satisf){
  if(x == k){
    satisf += collection[x];
    if(satisf > maxSatisf) maxSatisf = satisf;
  }

}

int main(){

  ifstream fin("file.in");
  ofstream fout("file.out");
  
  fin >> k >> trS >> aS;
  for(int i = 0; i < k; i++){
    fin >> collection[i];
  }

  find(1, 1);

  fin.close();
  fout.close();

  return 0;
}