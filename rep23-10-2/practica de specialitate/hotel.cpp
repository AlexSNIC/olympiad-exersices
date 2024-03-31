#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

typedef vector<vector<int>> Matrix;
typedef vector<int> Vector;
typedef vector<pair<int, int>> VecOfCoords;
typedef tuple<int, long long, VecOfCoords> Solution;

void printMat(Matrix mat){
  for(auto vec : mat){
    for(auto val : vec){
      cout << setw(3) << val << " ";
    }
    cout << endl;
  }
}

int getMatAt(int pozY, int pozX, Matrix& mat){
  size_t sizeY = mat.size(), sizeX = mat.at(0).size();
  int val;
  if(pozY < 0 || pozY >= sizeY) val = -1;
  else if(pozX < 0 || pozX >= sizeX) val = -1;
  else val = mat.at(pozY).at(pozX);

  return val;
}
Matrix getSumMatrix(Matrix& mat){
  size_t sizeY = mat.size(), sizeX = mat.at(0).size();
  Matrix sumMat(sizeY, Vector(sizeX, 0));
  sumMat.at(0) = mat.at(0);
  for(size_t i = 1; i < sizeY; i++){
    for(size_t j = 0; j < sizeX; j++){
      int val = getMatAt(i, j, mat);
      if(val <= 0) continue;
      int maxVal = max(max(getMatAt(i - 1, j - 1, sumMat), getMatAt(i - 1, j, sumMat)), getMatAt(i - 1, j + 1, sumMat));
      if(maxVal <= 0) sumMat.at(i).at(j) = 0;
      else{
        sumMat.at(i).at(j) = mat.at(i).at(j) + maxVal;
      }
    }
  }

  return sumMat;
}

VecOfCoords getMaxCoords(Matrix& mat){
  size_t sizeY = mat.size(), sizeX = mat.at(0).size();
  VecOfCoords vec;
  int nMax = -1;
  for(int i = 0; i < sizeY; i++){
    for(int j = 0; j < sizeX; j++){
      int val = mat.at(i).at(j);
      if(val > nMax){
        vec.clear();
        vec.push_back(make_pair(i, j));
        nMax = val;
      }
      else if(val == nMax){
        vec.push_back(make_pair(i, j));
      }
    }
  }

  return vec;
}

struct Path{
  long long sum = 0;
  VecOfCoords coords;
  
  Path(pair<int, int> start){
    coords.push_back(start);
  }
};

Solution getSolution(Matrix mat, VecOfCoords coords, Vector prices, Matrix altMat){
  vector<Path> paths;
  for(pair<int, int> coord : coords){
    paths.push_back(Path(coord));
  }
  int q = 0;
  for(Path& path : paths){
    auto [i, j] = path.coords.back();
    path.coords.pop_back();

    while(i != -1){
      int maxJ = j - 1;
      int maxVal = getMatAt(i, j - 1, mat);
      if(maxVal < getMatAt(i, j, mat)) maxJ = j;
      if(maxVal < getMatAt(i, j + 1, mat)) maxJ = j + 1;
      j = maxJ;
      path.coords.push_back(make_pair(i, j));
      i--;
    }
  }
  for(Path& path : paths){
    long long sum = 0;
    int i = 0;
    reverse(path.coords.begin(), path.coords.end());
    for(pair<int, int> coord : path.coords){
      sum += altMat.at(coord.first).at(coord.second) * prices.at(i);
      i++;
    }
    path.sum = sum;
  }

  int maxStudents = mat.at(coords.at(0).first).at(coords.at(0).second);
  long long minSum = INT_MAX;
  VecOfCoords maxVec;
  for(Path path : paths){
    if(minSum > path.sum){
      minSum = path.sum;
      maxVec = path.coords;
    }
  }

  return make_tuple(maxStudents, minSum, maxVec);
}

int main(){

  ifstream fin("hotel.in");
  ofstream fout("hotel.out");

  size_t sizeX, sizeY; fin >> sizeY >> sizeX;

  Matrix mat(sizeY, Vector(sizeX, 0));
  Vector prices;

  for(size_t i = 0; i < sizeY; i++){
    for(size_t j = 0; j < sizeX; j++){
      int val; fin >> val;
      mat.at(i).at(j) = val;
    }
  }

  for(size_t i = 0; i < sizeY; i++){
    int value; fin >> value;
    prices.push_back(value);
  }

  Matrix sumMat = getSumMatrix(mat);
  
  VecOfCoords maxCoords = getMaxCoords(sumMat);

  auto [maxStudents, minPrice, solutionVec] = getSolution(sumMat, maxCoords, prices, mat);

  cout << maxStudents << endl << minPrice << endl;
  for(auto[pozY, pozX] : solutionVec){

    cout << pozY + 1 << " " << pozX + 1 << endl;
  }
  

  fin.close();
  fout.close();

  return 0;
}