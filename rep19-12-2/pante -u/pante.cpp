#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int getMod(long long n){
  return n % int(pow(10, 9)) + 7;
}

int findP(string& a, int index){
  if(index >= a.length()) return 0;
  int sum = 0;


  // sum += findP(a, index + 1);

  sum = getMod(sum);
  return sum;
}

int main(){

  ifstream fin("pante.in");
  ofstream fout("pante.out");
  
  string a; string b;
  fin >> a >> b;
  a += '0';
  b += '0';

  int pantA = findP(a, 0);
  int pantB = findP(b, 0);
  
  cout << pantA << endl << pantB;

  fin.close();
  fout.close();

  return 0;
}