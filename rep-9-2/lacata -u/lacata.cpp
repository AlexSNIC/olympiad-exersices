#include <iostream>
#include <fstream>
using namespace std;


int minMoves = INT_MAX;
void findCode(){
  
}

int main(){

    ifstream fin("file.in");
    ofstream fout("file.out");

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