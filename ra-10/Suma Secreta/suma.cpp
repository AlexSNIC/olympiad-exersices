#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){

  ifstream fin("suma.in");
  ofstream fout("suma.out");
  short k; long n;
  fin >> k >> n;
  
  n += n * pow(10, k);
  int sum {};
  for(int i = 0; i < k; i++){
    int temp = n;
    temp /= pow(10, k - i);
    temp %= int(pow(10, k));
    sum += temp;
  }

  fout << sum;

  fin.close();
  fout.close();

  return 0;
  
}