#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <limits>
#include <algorithm>

#define NMAX 100

using namespace std;

struct Node{
  vector<int> neighbors;
  vector<int> sources;
  bool visited = false;
  int depth = -1;
};

void logQueue(deque<int>& queue, int depth = -1){
  for(int id : queue){
    cout << id << " ";
  }
  cout << "-depth: " << depth << endl;
}
void outputPath(vector<int> path, ofstream& fout){
  reverse(path.begin(), path.end());
  for(int id : path){
    fout << id << " ";
  }
  fout << endl;
}

void constructPath(vector<Node>& nodes, int goalId, int currentId, vector<int> currentPath, ofstream& fout){
  currentPath.push_back(currentId);
  if(currentId == goalId){
    outputPath(currentPath, fout);
    return;
  }
  for(int childId : nodes[currentId].sources){
    constructPath(nodes, goalId, childId, currentPath, fout);
  }

}

int main(){
  ifstream fin ("find.in");
  ofstream fout ("find.out");

  //undirected graph
  vector<Node> nodes(NMAX);
  int n; fin >> n;
  int fromId, toId; fin >> fromId >> toId;

  int inNode1, inNode2;
  while(fin >> inNode1 >> inNode2){
    nodes[inNode1].neighbors.push_back(inNode2);
    nodes[inNode2].neighbors.push_back(inNode1);
  }

  deque<int> queue;
  queue.push_front(fromId);
  nodes[fromId].depth = 0;
  int depthLimitId = fromId;
  int currentDepth = 0;

  while(!queue.empty()){
    int nodeId = queue.back();
    queue.pop_back();

    nodes[nodeId].depth = currentDepth;

    if(nodeId == depthLimitId){
      currentDepth++;
    }

    for(int neighborId : nodes[nodeId].neighbors){
      if(nodes[neighborId].depth == -1){
        queue.push_front(neighborId);
        nodes[neighborId].depth = -2;
      }
    }
    if(nodeId == depthLimitId){
      depthLimitId = queue.front();
    }
  }

  queue.push_front(fromId);
  nodes[fromId].visited = true;
  while(!queue.empty()){
    int nodeId = queue.back();
    queue.pop_back();

    for(int neighborId : nodes[nodeId].neighbors){
      if(!nodes[neighborId].visited){
        nodes[neighborId].visited = true;
        queue.push_front(neighborId);
      }
      if(nodes[neighborId].depth == nodes[nodeId].depth + 1){
        nodes[neighborId].sources.push_back(nodeId);
      }
    }
  }

  constructPath(nodes, fromId, toId, vector<int>(), fout);

  fin.close();
  fout.close();
}