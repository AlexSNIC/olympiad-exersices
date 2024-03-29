#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int getProfit(vector<int> stocks, int days, int nTr, long long tax){
  
}

int main(){

  ifstream fin("hedge.in");
  ofstream fout("hedge.out");

  int n; fin >> n;
  
  for(int i = 0; i < n; i++){
    int days, ts; long long tax;
    fin >> days >> ts >> tax;
    
    vector<int> stocks;
    for(int i = 0; i < days; i++){
      int k; fin >> k;
      stocks.push_back(k);
    }

    // cout << getProfit(stocks, days, ts, tax) << endl;
  }

  fin.close();
  fout.close();

  return 0;
}