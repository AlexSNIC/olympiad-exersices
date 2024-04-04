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

  int nrNodes, colors, edges;

  fin >> nrNodes >> colors >> edges;
  vector<Node> nodes(nrNodes + 1);

  for(int i = 1; i <= nrNodes; i++){
    int color; fin >> color;
    nodes.at(i).id = i;
    nodes.at(i).color = color;
  }
  int nodeId1, nodeId2;
  while(fin >> nodeId1 >> nodeId2){
    nodes.at(nodeId1).neighborsId.push_back(nodeId2);
    nodes.at(nodeId2).neighborsId.push_back(nodeId1);
  }
  int currentGraphId = -1;
  for(int i = 0; i <= nrNodes; i++){
    if(nodes.at(i).graphId != -1) continue;
    DFS(nodes, i, currentGraphId);
    currentGraphId++;
  }
  
  vector<vector<int>> colorGraph(currentGraphId, vector<int>(colors, 0));

  for(int i = 1; i <= nrNodes; i++){
    int nodeColor = nodes.at(i).color - 1;
    int nodeGraphId = nodes.at(i).graphId;

    colorGraph.at(nodeGraphId).at(nodeColor)++;
  }

  vector<int> totalSumGraph(currentGraphId);
  for(int i = 0; i < currentGraphId; i++){
    int sum = 0;
    for(int val : colorGraph.at(i)){
      sum += val;
    }
    totalSumGraph.at(i) = sum;
  }
  
  int totalSum = 0;

  for(int i = 0; i < currentGraphId; i++){
    vector<int>& graphColors = colorGraph.at(i);
    totalSum += totalSumGraph.at(i) * (totalSumGraph.at(i) - 1);
    for(int i = 0; i < colors; i++){
      
    }
  }
  cout << totalSum;
  fin.close();
  fout.close();
}