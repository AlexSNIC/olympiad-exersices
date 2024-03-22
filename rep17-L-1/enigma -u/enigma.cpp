#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
  ifstream fin("enigma.in");
  ofstream fout("enigma.out");

  string a, b; fin >> a >> b;
  int aLen = a.length();
  int bLen = b.length();
  int cLen = bLen - aLen + 1;
  long long totalSum = 0;
  vector<int> letters(25);
  
  for(int i = aLen; i < cLen; i++){
    char c = b.at(i);
    letters.at(c - 'a')++;
  }
  
  for(int i = 0; i < aLen; i++){
    
  }
  
  for(char c : a){

    totalSum += letters.at(c - 'a'); 
  }

  cout << totalSum;

  fin.close();
  fout.close();
}