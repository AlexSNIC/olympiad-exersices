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
      cout << i << endl;
      minVal = mat.at(queue.at(i).first).at(queue.at(i).second);
      minIndex = i;
    }
  }
  result = queue.at(minIndex);
  cout << "result: " << result.first << " " << result.second << endl;
  queue.erase(queue.begin() + minIndex);
  return result;
}

int main(){
  ifstream fin("radiatii.in");
  ofstream fout("radiatii.out");
  int sizeY, sizeX; fin >> sizeY >> sizeX;
  vector<vector<int>> mat(sizeY, vector<int>(sizeX));
  for(vector<int>& vec: mat)
    for(int& val : vec)
      fin >> val;
  
  deque<pair<int, int>> queue;
  push(queue, 0, 0);

  while(true){
    if(queue.empty()){
      cout << "queue was empty'd";
      break;
    }
    pair<int, int> coordinates = pop_smallest(queue, mat);
    if(coordinates.first < 0 || coordinates.first > sizeY)continue;
    if(coordinates.second < 0 || coordinates.second > sizeX)continue;
    
  }


  fin.close();
  fout.close();
  
}