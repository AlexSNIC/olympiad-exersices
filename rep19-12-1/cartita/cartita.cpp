#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node{
  int id;
  int parent = -1;
  int lChild = -1;
  int rChild = -1;
};

vector<Node> nodes;

void AddTie(int parent, int child, char dir){
  nodes.at(child).parent = parent;
  if(dir == 'D'){
    nodes.at(parent).rChild = child;
  }
  else{
    nodes.at(parent).lChild = child;
  }
};

int findPath(char dir, int current, int level, int lastLevel){
  if(level == lastLevel) return current;
  
  int res = -1;

  int next = (dir == 'D'? nodes.at(current).rChild : nodes.at(current).lChild);
  if(next != -1) 
    res = findPath(dir, next, level + 1, lastLevel);
  if(res != -1) return res;

  next = (dir == 'R'? nodes.at(current).rChild : nodes.at(current).lChild);
  if(next != -1) res = findPath(dir, next, level + 1, lastLevel);
  return res;
}

int main(){

  ifstream fin("cartita.in");
  ofstream fout("cartita.out");
  
  int N, K;
  fin >> N >> K;
  nodes.resize(N + 1);
  for(int i = 1; i <= N; i++){
    nodes.at(i).id = i;
  }

  for(int i = 1; i <= N - 1; i++){
    int parent, child;
    char dir;
    fin >> parent >> child >> dir;
    AddTie(parent, child, dir);
  }
  int root = -1;
  for(int i = 1; i <= N; i++){
    if(nodes.at(i).parent == -1){
      root = i;
    }
  }
  if(root == -1){
    cout << "no root found";
    return 404;
  }
  int right = findPath('D', root, 0, K);
  int left = findPath('L', root, 0, K);

  cout << right << " " << left;


  fin.close();
  fout.close();

  return 0;
}