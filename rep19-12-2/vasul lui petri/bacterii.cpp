#include <iostream>
#include <fstream>
#include <deque>

using namespace std;


int main(){

  ifstream fin("bacterii.in");
  ofstream fout("bacterii.out");

  int n, lifetime, totalTime;
  fin >> n >> lifetime >> totalTime;

  long long total = n;
  deque<long long> rounds {0};

  for(int i = 1; i < totalTime; i++){
    int bornThisGeneration = total;
    total += rounds[0];
    rounds.push_front(bornThisGeneration);

    if(i >= lifetime){
      total -= rounds.back();
      rounds.pop_back();
    }
  }

  fout << total;
  

  fin.close();
  fout.close();

  return 0;
}