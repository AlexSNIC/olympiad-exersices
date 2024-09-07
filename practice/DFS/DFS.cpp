#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
typedef std::vector<std::vector<int>> Mat;

void print(const Mat& mat){
  for(const std::vector<int>& vec: mat){
    for(const int& val: vec){
      std::cout << std::setw(3) << val;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool find(Mat& mat, int x, int y, int endX, int endY){
  if(x < 0 || x >= mat.at(0).size()) return false;
  if(y < 0 || y >= mat.size()) return false;
  if(x == endX && y == endY){
    // print(mat);  // verify path
    return true;
  } 
  if(mat.at(y).at(x) == 1 || mat.at(y).at(x) == -1) return false;
  mat.at(y).at(x) = 1;

  bool result = false;
  result |= find(mat, x + 1, y, endX, endY);
  result |= find(mat, x, y + 1, endX, endY);
  result |= find(mat, x - 1, y, endX, endY);
  result |= find(mat, x, y - 1, endX, endY);

  mat.at(y).at(x) = 0;

  return result;
}

int main(){
  std::ifstream fin("DFS.in");

  std::size_t sizeX, sizeY, startX, startY, endX, endY;
  fin >> sizeY >> sizeX;
  fin >> startY >> startX;
  fin >> endY >> endX;
  Mat mat(sizeY, std::vector<int>(sizeX));
  for(std::vector<int>& vec : mat){
    for(int& val: vec){
      int temp; fin >> temp;
      val = -temp;
    }
  }
  std::cout << std::boolalpha << find(mat, startX, startY, endX, endY);

  fin.close();
  return 0;
}
