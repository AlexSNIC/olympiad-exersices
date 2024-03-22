#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

bool isViable(int pozY, int pozX, size_t n){
  if(pozX <= 0 || pozY <= 0) return false;
  if(pozX > pozY) return false;
  if(pozY > n) return false;

  return true;
}
bool isViable(pair<int, int> poz, size_t n){
  if(poz.first <= 0 || poz.second <= 0) return false;
  if(poz.second > poz.first) return false;
  if(poz.second > n) return false;

  return true;
}

pair<int, int> pop_smallest(vector<pair<int, int>>& stack, vector<vector<int>>& sums){
  size_t maxSize = sums.size();
  int minWeight = INT_MAX;
  int minIndex;
  int i = 0;
  for(pair<int, int> poz : stack){
    if(!isViable(poz, maxSize)){
      stack.erase(stack.begin() + i);
      continue;
    }
    int weight = sums.at(poz.first).at(poz.second);
    if(weight < minWeight){
      minWeight = weight;
      minIndex = i;
    }
    i++;
  }
  cout << minIndex << endl;
  pair<int, int> minPair = stack.at(minIndex);
  stack.erase(stack.begin() + minIndex);
  return minPair;
}

void dijkstra(vector<vector<int>>& mat, vector<pair<int, int>>& stack){
  size_t maxSize = mat.size();
  vector<vector<int>> sums(maxSize, vector<int>(maxSize, INT_MAX));

  sums.at(1).at(1) = mat.at(1).at(1);
  sums.at(2).at(1) = mat.at(1).at(1) + mat.at(2).at(1);
  sums.at(2).at(2) = mat.at(1).at(1) + mat.at(2).at(2);
  stack.push_back(make_pair(1, 1));
  pair<int, int> poz;

  while(true){
    if(stack.empty()){
      cout << "Error: empty stack" << endl;
      break;
    }
    poz = pop_smallest(stack, sums);
    if(poz.first == maxSize - 1)break;

    if(isViable(poz.first + 1, poz.second - 1, maxSize) && sums.at(poz.first + 1).at(poz.second - 1) != INT_MAX){
      sums.at(poz.first + 1).at(poz.second - 1) = sums.at(poz.first).at(poz.second) + mat.at(poz.first + 1).at(poz.second - 1);
      stack.push_back(make_pair(poz.first + 1, poz.second - 1));
      cout << "1";
    }
    if(isViable(poz.first + 1, poz.second, maxSize) && sums.at(poz.first + 1).at(poz.second) != INT_MAX){
      sums.at(poz.first + 1).at(poz.second) = sums.at(poz.first).at(poz.second) + mat.at(poz.first + 1).at(poz.second);
      stack.push_back(make_pair(poz.first + 1, poz.second));
      cout << "2";
    }
    if(isViable(poz.first + 1, poz.second + 1, maxSize) && sums.at(poz.first + 1).at(poz.second + 1) != INT_MAX){
      sums.at(poz.first + 1).at(poz.second + 1) = sums.at(poz.first).at(poz.second) + mat.at(poz.first + 1).at(poz.second + 1);
      stack.push_back(make_pair(poz.first + 1, poz.second + 1));
      cout << "3";
    }
  }

  cout << sums.at(poz.first).at(poz.second);
}

int main(){
  ifstream fin("triunghi.in");
  ofstream fout("triunghi.out");

  size_t n; fin >> n;
  vector<vector<int>> mat(n + 1, vector<int>(n + 1, INT_MAX));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
      int temp; fin >> temp;
      mat.at(i).at(j) = temp;
    }
  }
  
  vector<pair<int, int>> stack;

  dijkstra(mat, stack);


  fin.close();
  fout.close();

  return 0;
}