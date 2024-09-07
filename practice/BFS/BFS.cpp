#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <deque>

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

struct Coord{
  int x;
  int y;
  Coord(int x, int y) : x(x), y(y){};
};

int find(Mat mat, int startX, int startY, int endX, int endY){
  std::deque<Coord> queue;
  int x = startX, y = startY;
  Coord lastDepth(x, y);
  int depth = 1;
  int max = -1;
  while(true){
    Coord coord = queue.front();
    queue.pop_front();
    x = coord.x;
    y = coord.y;
    bool isInBounds = true;
    if(x < 0 || x >= mat.at(0).size()) isInBounds = false;
    if(y < 0 || y >= mat.size()) isInBounds = false;

    if(isInBounds && mat.at(y).at(x) == 0){
      mat.at(y).at(x) = depth;
      if(endX == x && endY == y) return depth - 1;
      queue.push_back(Coord(x + 1, y));
      queue.push_back(Coord(x, y - 1));
      queue.push_back(Coord(x - 1, y));
      queue.push_back(Coord(x, y + 1));
    }

    if(lastDepth.x == x && lastDepth.y == y) {
      depth++;
      lastDepth.x = queue.back().x;
      lastDepth.y = queue.back().y;
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

  std::cout << find(mat, startX, startY, endX, endY) << std::endl;
  return 0;
}