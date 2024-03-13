#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

struct Path{
  int neighborId;
  int weight;
  Path(int neighbor, int w): weight(w), neighborId(neighbor){};
};
struct Node{
  int id;
  bool visited = false;
  int time = INT_MAX;
  vector<Path> neighbors;
};

vector<Node> nodes;

int findMinTime(){
  int minNodeId = -1;
  for(Node node : nodes){
    if(!node.visited){
      if(minNodeId == -1) minNodeId = node.id;
      else if(node.time < nodes.at(minNodeId).time)
        minNodeId = node.id;
    }
  }
  return minNodeId;
}

void dijkstra(){
  for(int i = 0; i < nodes.size(); i++){
    int minId = findMinTime();
    nodes.at(minId).visited = true;

    for(Path path : nodes.at(minId).neighbors){
      nodes.at(path.neighborId).time = nodes.at(minId).time + path.weight;
    }
  }
}


int main(){

  ifstream fin("timp.in");
  ofstream fout("timp.out");
  int n; fin >> n;
  int nPaths; fin >> nPaths;
  int startNode; fin >> startNode; startNode--;
  nodes.resize(n);

  int from, to, weight;
  for(int i = 0; i < nodes.size(); i++){
    nodes.at(i).id = i;
  }

  while(fin >> from >> to >> weight){
    from--; to--;
    nodes.at(from).neighbors.push_back(Path(to, weight));
  };

  nodes.at(startNode).visited = false;
  nodes.at(startNode).time = 0;
  dijkstra();

  int minTime = -1;
  for(Node node : nodes){
    if(node.time == INT_MAX){
      minTime = -1;
      break;
    }
    if(node.time > minTime){
      minTime = node.time;
    }
  }

  cout << minTime;

  fin.close();
  fout.close();

  return 0;
}