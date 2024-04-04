#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

struct Node{
  int id;
  int color;
  int graphId = -1;
  vector<int> neighborsId;
};

void DFS(vector<Node>& nodes, int startNode, int graphId){
  deque<int> queue {startNode};
  nodes.at(startNode).graphId = graphId;

  while(!queue.empty()){
    int nodeId = queue.back(); queue.pop_back();
    for(int neighborId : nodes.at(nodeId).neighborsId){
      if(nodes.at(neighborId).graphId != -1) continue;

      nodes.at(neighborId).graphId = graphId;
      queue.push_back(neighborId);
    }
  }
}

int main(){
  ifstream fin("drumuri.in");
  ofstream fout("drumuri.out");

  
  
  fin.close();
  fout.close();
}