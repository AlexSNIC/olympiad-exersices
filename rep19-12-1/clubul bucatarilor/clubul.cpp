#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main(){

  ifstream fin("clubul.in");
  
  int R, N, K, P;
  fin >> N >> K >> R;
  vector<int> rounds(R);
  for(int i = R - 1; i >= 0; i--){
    int temp;
    fin >> temp;
    rounds.at(i) = temp;
  }
  fin >> P;


  for(int i = 0; i < R; i++){
    int poz = rounds.at(i);
    if(P == N) P = poz;
    else if(P > poz) P++;
  }

  cout << P << endl;


  fin.close();

  return 0;
}