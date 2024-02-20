#include <iostream>
#include <fstream>
using namespace std;

int solution(int n, int nrBricks = 2){
  if(n < 0) return 0;
  if(n == 0) {
    return 1;
  }
  int solutions {};
  solutions += solution(n - 1, nrBricks);
  solutions += solution(n - 2, nrBricks);
  if(nrBricks == 3)
    solutions += solution(n - 3, nrBricks);

  return solutions;
}



int main(){

  ifstream fin("caramizi.in");
  ofstream fout("caramizi.out");
  int n; fin >> n; n/= 2;

  solution(n);

  fout << solution(n) << endl << solution(n, 3);

  fin.close();
  fout.close();

  return 0;
}