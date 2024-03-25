#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <deque>

using namespace std;

void print(vector<vector<int>>& mat);

struct Poz{
  int x, y;
  poz(int pozY, int pozX) : x(pozX), y(pozY) {};
}

int main(){
  ifstream fin("ursul.in");
  ofstream fout("ursul.out");

  int n, s; fin >> n >> s;
  int startPozX, startPozY;
  int endPozX, endPozY;

  vector<vector<int>> mat(n, vector<int>(n));
  vector<deque<Poz>> queueNr(2);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      char c; fin >> c;
      if(c == 'G') mat.at(i).at(j) = 0;
      else if(c == 'T') mat.at(i).at(j) = -1;
      else if(c == 'M') {
        mat.at(i).at(j) = 0;
        startPozY = i;
        startPozX = j;
      }
      else if(c == 'D') {
        mat.at(i).at(j) = -1;
        endPozY = i;
        endPozX = j;
      }
      else if(c == 'H') {
        mat.at(i).at(j) = -1;
        queue.at(0).push_back(Poz(i, j));
      }
    }
  }

  while(!queueNr.empty()){

  }

  print(mat);


  


  fin.close();
  fout.close();
}


void print(vector<vector<int>>& mat){
  for(vector<int> vec : mat){
    for(int val : vec){
      cout << setw(3) << val;
    }
    cout << endl;
  }
}