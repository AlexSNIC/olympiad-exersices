#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


int minMoves = INT_MAX;
int getIndex(int code, int index){
  int temp = code;
  temp /= pow(10, index);
  temp %= 10;
  return temp;
}
int changeCode(int code, int poz, int by){
  int temp = getIndex(code, poz);
  code -= temp * int(pow(10, poz - 1));
  temp = (temp + by) >= 0? (temp + by) % 10: (10 + temp + by) % 10;
  code += temp * int(pow(10, poz - 1));
  return code;
}
void findCode(vector<int>& blockCodes, int code, int moves){
  
  
}

int main(){

    ifstream fin("lacata.in");
    ofstream fout("lacata.out");

    short code; fin >> code;
    short nBlockCodes; fin >> nBlockCodes;
    short blocks[nBlockCodes];
    for(int i = 0; i < nBlockCodes; i++){
      fin >> blocks[i];
    }

    fin.close();
    fout.close();


  return 0;
}