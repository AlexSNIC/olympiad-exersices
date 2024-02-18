#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Relative{
  int degree;
  string genetics;
};
int findDegree(string Monea, string otherCat){
  int sum = 0;
  int len = min(Monea.length(), otherCat.length());
  for(int i = 0; i < len; i++){
    if(Monea[i] == otherCat[i]) sum++;
  }
  return sum;
}

struct R1{
  string genetics;
  int y, x;

  R1(string genetics, int y, int x): genetics(genetics), y(y), x(x){}
};
void findR1(vector<vector<Relative>>& relatives, ofstream& fout, int rows, int cols, int GMax){
  int max = 0;
  vector<R1> results;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(relatives.at(i).at(j).degree > max){
        max = relatives.at(i).at(j).degree;
        results.clear();
        results.push_back(R1(relatives.at(i).at(j).genetics, i, j));
      }
      else if(relatives.at(i).at(j).degree == max){
        results.push_back(R1(relatives.at(i).at(j).genetics, i, j));
      }
    }
  }
  if(max < GMax){
    fout << "MONEA NU ARE RUDE";
    return;
  }
  fout << max << endl;
  for(R1 result : results){
    fout << result.y + 1 << ' ' << result.x + 1 << ' ' << result.genetics << endl;
  }

}

int findSquareSize(vector<vector<bool>>& mat, int row, int col, int rows, int cols, int size){
  if(row + size >= rows)return size;
  if(col + size >= cols)return size;
  for(int i = 0; i <= size; i++){
    if(row + i >= rows) return size;
    if(col + i >= cols) return size;
    if(!mat.at(row + i).at(col + size))
      return size;
    if(!mat.at(row + size).at(col + i))
      return size;
  }
  return findSquareSize(mat, row, col, rows, cols, size + 1);
}

void findR2(vector<vector<bool>>& mat, int rows, int cols, ofstream& fout){
  int maxSize = 0;
  int row, col;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      int squareSize = findSquareSize(mat, i, j, rows, cols, 0);
      if(maxSize < squareSize){
        maxSize = squareSize;
        row = i;
        col = j;
      }
    }
  }
  if(maxSize == 0){
    fout << "MONEA NU ARE RUDE";
    return;
  }
  fout << row + 1 << ' ' << col + 1 << ' ' << maxSize;
}

int main(){
  ifstream fin("experimente.in");
  ofstream fout("experimente.out");

  int R; fin >> R;
  int rows, cols; fin >> rows >> cols;
  int G; fin >> G;
  string Monea; fin >> Monea;
  vector<vector<Relative>> relatives(rows, vector<Relative>(cols));
  vector<vector<bool>> values(rows, vector<bool>(cols));

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      string temp; fin >> temp;
      int deg = findDegree(Monea, temp);
      relatives.at(i).at(j).genetics = temp;
      relatives.at(i).at(j).degree = deg;
      values.at(i).at(j) = deg > G;
    }
  }
  
  if(R == 1){
    findR1(relatives, fout, rows, cols, G);
    return 0;
  }
  findR2(values, rows, cols, fout);
  


  fin.close();
  fout.close();
  return 0;
}