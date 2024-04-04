#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// vector<long long> getFactorials(){
//   int nmax = 20;
//   vector<long long> factorials(nmax, 0);
//   factorials.at(1) = 1;
//   factorials.at(2) = 2;
//   for(int i = 3; i < nmax; i++){
//     long long factor = factorials.at(i - 1) * i;
//     factorials.at(i) = factor;
//   }

//   return factorials;
// }

int main(){
  ifstream fin("factor.in");
  ofstream fout("factor.out");

  long long n;
  fin >> n;
  
  vector<long long> factorials {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000};

  int k = 17;

  vector<int> nFactorial(k + 1);

  while(n != 0){
    int kSum = 0;
    while(n >= factorials.at(k)){
      n-= factorials.at(k);
      kSum++;
    }
    nFactorial.at(k) = kSum;

    k--;
  }
  
  for(int i = nFactorial.size() - 1; i > 0; i--){
    if(nFactorial.at(i) != 0) break;

    nFactorial.pop_back();
  }
  reverse(nFactorial.begin(), nFactorial.end());

  for(int val : nFactorial) fout << val << " ";

  fin.close();
  fout.close();
  
  return 0;
}