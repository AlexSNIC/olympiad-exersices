#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node{
  int id;
  int parentNode = -1;
  int leftNode = -1;
  int rightNode = -1;
};

int findLeftPath(vector<Node>& nodes, int currentLevel, int targetLevel, bool backtrack = false);

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

  fin.close();
  fout.close();

  return 0;
}

int findLeftPath(vector<Node>& nodes, int currentNode, int currentLevel, int targetLevel, bool backtrack = false){
  if(currentLevel == targetLevel) return currentNode;
  int availableBranch = 0;
  if(nodes.at(currentNode).leftNode != -1) availableBranch = 1;
  else if(nodes.at(currentNode).rightNode != -1) availableBranch = -1;
  if(availableBranch == 0) return -1;


  int nextNode;
  if(availableBranch == -1) nextNode = nodes.at(currentNode).leftNode;
  int result = findLeftPath(nodes, nextNode, currentLevel + 1, targetLevel);

}