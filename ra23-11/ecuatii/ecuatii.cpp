#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


int main(){

  ifstream fin("ecuatii.in");
  ofstream fout("ecuatii.out");

  int n; fin >> n;
  vector<int> a;
  a.reserve(1000);
  for(int i = 0; i <= n; i++){
    double st = sqrt(i);
    if(st - floor(st) == 0)
      a.push_back(int(st));
  }

  for(int i = 0; i < a.size(); i++){
    for(int j = a.size(); j >= i; j--){
      if(a[i] + a[j] == a[a.size() - 1]) fout << a[i] << " " << a[j] << endl;
    }
  }

  fin.close();
  fout.close();
  

  return 0;
}