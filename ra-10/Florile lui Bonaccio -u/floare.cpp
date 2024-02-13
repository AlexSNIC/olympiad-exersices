#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int findFib(vector<int>& fib, int n){
  if(n == 0) return 0;
  if(n == 1) return 1;

  if(fib.at(n - 2) == 0) findFib(fib, n - 2);
  if(fib.at(n - 1) == 0) findFib(fib, n - 1);

  fib.at(n) = fib.at(n - 1) + fib.at(n - 2);
  return fib.at(n);
}

int main(){


  ifstream fin("floare.in");
  ofstream fout("floare.out");
  int n; fin >> n;
  vector<int> fib(40);
  fib.at(0) = 0;
  fib.at(1) = 1;
  findFib(fib, 39);
  reverse(fib.begin(), fib.end());

  vector<int> answer;
  for(int value : fib){
    if(n - value >= 0){
      n-=value;
      answer.push_back(value);
    }
  }

  for(int value : answer){
    if(value != 0)
    cout << value << endl;
  }
  




  fin.close();
  fout.close();
}