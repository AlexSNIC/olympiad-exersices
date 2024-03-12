#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <utility>
#include <limits>

using namespace std;

void push(deque<pair<int, int>>& queue, int y, int x){
  queue.push_front(make_pair(y, x));
}
pair<int, int> pop_smallest(deque<pair<int, int>>& queue, vector<vector<int>>& mat){
  pair<int, int> result;
  int minVal = INT_MAX;
  int minIndex = -1;
  for(int i = 0; i < queue.size(); i++){
    if(mat.at(queue.at(i).first).at(queue.at(i).second) < minVal){
      minVal = mat.at(queue.at(i).first).at(queue.at(i).second);
      minIndex = i;
    }
  }
  result = queue.at(minIndex);
  queue.erase(queue.begin() + minIndex);
  return result;
}

void addToQueue(deque <pair<int, int>>& queue, vector<vector<int>>& weights, vector<vector<int>>& mat, int y, int x, pair<int, int> prevCoords){
  if(y < 0 || y >= weights.size())return;
  if(x < 0 || x >= weights.at(0).size())return;
  if(mat.at(y).at(x) != -1)return;
  pair<int, int> coordinates = make_pair(y, x);
  mat.at(y).at(x) = mat.at(prevCoords.first).at(prevCoords.second) + weights.at(y).at(x);
  queue.push_back(coordinates);
}

int main(){
  ifstream fin("radiatii.in");
  ofstream fout("radiatii.out");
  int sizeY, sizeX; fin >> sizeY >> sizeX;
  vector<vector<int>> mat(sizeY, vector<int>(sizeX, -1));
  vector<vector<int>> weights(sizeY, vector<int>(sizeX));
  for(vector<int>& vec: weights)
    for(int& val : vec)
      fin >> val;
    mat.at(0).at(0) = weights.at(0).at(0);
  
  deque<pair<int, int>> queue;
  push(queue, 0, 0);

  while(true){
    if(queue.empty()){
      break;
    }
    pair<int, int> coordinates = pop_smallest(queue, mat);
    if(coordinates.first < 0 || coordinates.first >= sizeY)continue;
    if(coordinates.second < 0 || coordinates.second >= sizeX)continue;
    
    addToQueue(queue, weights, mat, coordinates.first + 1, coordinates.second, coordinates);
    addToQueue(queue, weights, mat, coordinates.first, coordinates.second + 1, coordinates);
    addToQueue(queue, weights, mat, coordinates.first - 1, coordinates.second, coordinates);
    addToQueue(queue, weights, mat, coordinates.first, coordinates.second - 1, coordinates);
  }
  fout << mat.at(sizeY - 1).at(sizeX - 1);

  fin.close();
  fout.close();
  
}