#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
  ifstream fin("enigma.in");
  ofstream fout("enigma.out");

  string a, b; fin >> a >> b;
  int cLen = b.length() - a.length() + 1;

  int aLen = a.length();
  vector<int> cores(cLen);

  int i = -1;
  for(int& core : cores){
    int n = 0; i++;
    for(int index = i, j = 0; j < aLen; index++, j++)
        if(b.at(index) == a.at(j))n++;
    core = n;
  }

  long long totalSum = 0;
  for(int core : cores){
    totalSum += core;
  }

  cout << totalSum;

  fin.close();
  fout.close();
}