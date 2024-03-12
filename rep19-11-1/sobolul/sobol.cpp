#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;

struct Node{
  int id;
  int parentNode = -1;
  int leftNode = -1;
  int rightNode = -1;
};

void pushNodes(deque<int>& queue, Node node){
  if(node.leftNode != -1) queue.push_front(node.leftNode);
  if(node.rightNode != -1) queue.push_front(node.rightNode);
}

int main(){

  ifstream fin("sobol.in");
  ofstream fout("sobol.out");
  
  int n; fin >> n;
  int level; fin >> level;
  vector<Node> nodes(n + 1);
  int parent, child; char direction;
  for(int i = 0; i < n; i++){
    nodes.at(i).id = i;
  }
  nodes.at(0).parentNode = 0;
  while(fin >> parent >> child >> direction){
    if(direction == 'S') 
      nodes.at(parent).leftNode = child;
    else nodes.at(parent).rightNode = child;
    nodes.at(child).parentNode = parent;
  }
  int rootNode;
  for(Node node : nodes){
    if(node.parentNode == -1) {
      rootNode = node.id;
      break;
    }
  }

  bool code = 0;
  vector<deque<int>> queue(2);
  int currentLevel = 0;
  queue.at(0).push_back(rootNode);
  while(!(queue.at(0).empty() && queue.at(1).empty())){
    if(queue.at(code).empty()){
      currentLevel++;
      code = !code;
      continue;
    }
    if(currentLevel == level){
      fout << queue.at(code).back() << " " << queue.at(code).front() << endl;
      break;
    }
    int currentNode = queue.at(code).back();
    queue.at(code).pop_back();
    pushNodes(queue.at(!code), nodes.at(currentNode));
  }

  fin.close();
  fout.close();

  return 0;
}