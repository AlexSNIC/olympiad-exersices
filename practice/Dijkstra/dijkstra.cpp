#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <deque>

typedef std::vector<std::vector<int>> Mat;
const int inf = 100000;
void print(const Mat& mat){
  for(const std::vector<int>& vec: mat){
    for(const int& val: vec){
      std::cout << std::setw(3) << val;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
struct Coord{
  int x;
  int y;
  Coord(int x, int y) : x(x), y(y){};
};
int dijkstra(const Mat costMat, int startX, int startY, int endX, int endY){
  Mat mat(costMat.size(), std::vector<int>(costMat.at(0).size(), inf));
  std::deque<Coord> queue;
  queue.emplace_back(startX, startY);
  mat.at(startX).at(startY) = costMat.at(startX).at(startY);

  auto safeCheck = [mat](int x, int y){
    bool isSafe = true;
    if(x < 0 || x >= mat.at(0).size()) isSafe = false;
    if(y < 0 || y >= mat.size()) isSafe = false;
    return isSafe;
  } 

  while(true){
    const Coord coord = 
    
    const int x = coord.x;
    const int y = coord.y;

    if(safeCheck(x, y)){
      const int cellCost = mat.at(y).at(x);
      if(safeCheck(x + 1, y)){
        const int prevCost = mat.at(y).at(x + 1);
        const int currentCost = cellCost + costMat.at(y).at(x + 1);
        if(prevCost < currentCost){
          mat.at(y).at(x + 1) = currentCost;
        }
      }
    }
    
    


  }
}

int main(){
  std::ifstream fin("BFS.in");

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
  fin.close();

  dijkstra(mat, startX, startY, endX, endY);
  
  return 0;
}