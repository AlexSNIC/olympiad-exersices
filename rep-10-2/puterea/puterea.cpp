#include <iostream>
#include <fstream>
using namespace std;

int rec(int x, int n){
  if(x == 0) return 0;
  
  int count = 0, temp = x;
  while(temp != 0){
    if(temp % n == 0){
      count++;
    }
    temp /= n;
  }

  return count + rec(x - 1, n);
}

int main(){

  ifstream fin("puterea.in");
  ofstream fout("puterea.out");

  int n, p;
  fin >> n >> p;

  int sum = rec(n, p);
  fout << sum;

  fin.close();
  fout.close();

  return 0;
}