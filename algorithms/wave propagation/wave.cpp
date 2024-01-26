#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <iomanip>

using namespace std;



struct Cell{
  int x;
  int y;

  bool isEqual(Cell cell){
    if(x == cell.x && y == cell.y)return true;
    return false;
  }

  Cell(int valX, int valY) : x(valX), y(valY) {};
};

void print(vector<vector<int>>& mat){
  for(vector<int>& arr : mat){
    for(int val : arr){
      cout << setw(2) << val << ' ';
    }
    cout << endl;
  }
}
void print(deque<Cell>& queue){
  for(Cell cell : queue){
    cout << cell.x << " " << cell.y << "; ";
  }
  cout << endl;
}

int main(){
  ifstream fin ("wave.in");
  ofstream fout ("wave.out");

  int sizeX, sizeY;
  fin >> sizeX >> sizeY;
  int startY, startX, endY, endX;
  fin >> startY >> startX >> endY >> endX;

  vector<vector<int>> mat(sizeY, vector<int>(sizeX));
  for(vector<int>& arr : mat){
    for(int& val : arr){
      int readVal; fin >> readVal;
      val = readVal * -1;
    }
  }

  deque<Cell> queue;
  Cell queueLimit(startX, startY);
  int depth = 1;

  queue.push_front(Cell(startX, startY));
  while(!queue.empty()){
    Cell cell = queue.back();
    queue.pop_back();
    if(mat[cell.y][cell.x] != 0){
      if(cell.isEqual(queueLimit)){
        depth++;
        queueLimit = queue.front();
      }
      continue;
    }

    mat[cell.y][cell.x] = depth;

    if(cell.x + 1 < sizeX)
      queue.push_front(Cell(cell.x + 1, cell.y));
    if(cell.y + 1 < sizeY)
      queue.push_front(Cell(cell.x, cell.y + 1));
    if(cell.x - 1 >= 0)
      queue.push_front(Cell(cell.x - 1, cell.y));
    if(cell.y - 1 >= 0)
      queue.push_front(Cell(cell.x, cell.y - 1));

    if(cell.isEqual(queueLimit)){
      depth++;
      queueLimit = queue.front();
    }

  }
  
  fout << mat[endY][endX];




  fin.close();
  fout.close();
}