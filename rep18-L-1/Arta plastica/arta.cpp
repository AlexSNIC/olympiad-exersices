#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void print(vector<vector<bool>>& mat){
  for(vector<bool> vec : mat){
    for(bool val : vec){
      cout << val << ' ';
    }
    cout << endl;
  }
}
int sum(vector<vector<bool>>& mat){
  int sum{};
  for(vector<bool> vec : mat){
    for(bool val : vec){
      sum += val;
    }
  }
  return sum;
}

void addSquare(vector<vector<bool>>& mat, int xStart, int yStart, int xEnd, int yEnd){
  for(int i = yStart; i < yEnd; i++){
    for(int j = xStart; j < xEnd; j++){
      mat.at(i).at(j) = 0;
    }
  }
}

int main(){
  ifstream fin("arta.in");
  ofstream fout("arta.out");

  int width, height;
  fin >> width >> height;
  int n; fin >> n;
  vector<vector<bool>> mat(height, vector<bool>(width, 1));
  int xStart, yStart, xEnd, yEnd;
  while(fin >> xStart >> yStart >> xEnd >> yEnd){
    addSquare(mat, xStart, yStart, xEnd, yEnd);
  }
  print(mat);
  cout << sum(mat);



  fin.close();
  fout.close();
  return 0;
}