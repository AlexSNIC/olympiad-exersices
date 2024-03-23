#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>

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
  pair<int, int> minPair = stack.at(minIndex);
  stack.erase(stack.begin() + minIndex);
  return minPair;
}

pair<int, int> pop_biggest(vector<pair<int, int>>& stack, vector<vector<int>>& sums){
  size_t maxSize = sums.size();
  int maxWeight = INT_MIN;
  int maxIndex;
  int i = 0;
  for(pair<int, int> poz : stack){
    if(!isViable(poz, maxSize)){
      stack.erase(stack.begin() + i);
      continue;
    }
    int weight = sums.at(poz.first).at(poz.second);
    if(weight > maxWeight){
      maxWeight = weight;
      maxIndex = i;
    }
    i++;
  }
  pair<int, int> maxPair = stack.at(maxIndex);
  stack.erase(stack.begin() + maxIndex);
  return maxPair;
}
void print(vector<vector<int>> mat){
  for(auto vec : mat){
    for(int val : vec){
      cout << setw(4) << val << " ";
    }
    cout << endl;
  }
}

int dijkstra(vector<vector<int>>& mat, bool findSmallest){
  size_t maxSize = mat.size();
  vector<vector<int>> sums(maxSize, vector<int>(maxSize, INT_MAX));
  vector<pair<int, int>> stack;
  sums.at(1).at(1) = mat.at(1).at(1);
  stack.push_back(make_pair(1, 1));
  pair<int, int> poz;

  while(true){
    if(stack.empty()){
      cout << "Error: empty stack" << endl;
      break;
    }
    if(findSmallest) poz = pop_smallest(stack, sums);
    else poz = pop_biggest(stack, sums);
    if(poz.first == maxSize - 1)break;

    if(isViable(poz.first + 1, poz.second - 1, maxSize) && sums.at(poz.first + 1).at(poz.second - 1) == INT_MAX){
      sums.at(poz.first + 1).at(poz.second - 1) = sums.at(poz.first).at(poz.second) + mat.at(poz.first + 1).at(poz.second - 1);
      stack.push_back(make_pair(poz.first + 1, poz.second - 1));
    }
    if(isViable(poz.first + 1, poz.second, maxSize) && sums.at(poz.first + 1).at(poz.second) == INT_MAX){
      sums.at(poz.first + 1).at(poz.second) = sums.at(poz.first).at(poz.second) + mat.at(poz.first + 1).at(poz.second);
      stack.push_back(make_pair(poz.first + 1, poz.second));
    }
    if(isViable(poz.first + 1, poz.second + 1, maxSize) && sums.at(poz.first + 1).at(poz.second + 1) == INT_MAX){
      sums.at(poz.first + 1).at(poz.second + 1) = sums.at(poz.first).at(poz.second) + mat.at(poz.first + 1).at(poz.second + 1);
      stack.push_back(make_pair(poz.first + 1, poz.second + 1));
    }
  }

  return sums.at(poz.first).at(poz.second);
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

  cout << dijkstra(mat, true) << ' ' << dijkstra(mat, false);



  fin.close();
  fout.close();

  return 0;
}