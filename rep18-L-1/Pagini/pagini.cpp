#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int findSum(int index, string& s, const int mid){
  if(index == -1) return 0;
  int validity = 0;
  if(index == mid){
    string lower = s.substr(0, mid + 1), 
           higher = s.substr(mid + 1);
    validity = lower.compare(higher);
    cout << lower << endl << higher << endl << validity << endl;

  }

  if(s.at(index) == '0' || validity > 0) return findSum(index - 1, s, mid);
  return 1 + findSum(index - 1, s, mid);
}

int main(){
  ifstream fin("pagini.in");
  ofstream fout("pagini.out");

  string s; fin >> s;
  
  int mid = s.length() / 2 - 1;
  int sum = findSum(mid, s, mid);

  fout << sum;
  cout << sum;

  fin.close();
  fout.close();

  return 0;
}