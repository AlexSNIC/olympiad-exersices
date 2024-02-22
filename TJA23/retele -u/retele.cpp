#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Link{
  int toNode;
  int weight;
  int fromNode;

  Link(int from, int to, int w) : fromNode(from), toNode(to), weight(w) {};
};
struct Node{
  vector<Link> links;
  bool visited = false;
  bool explored = false;
};

void resetGraph(vector<Node>& graph){
  for(Node& node : graph){
    node.visited = false;
  }
}

void findMin(vector<Node>& graph, int nodeId, Link& minLink){
  for(Link link : graph[nodeId].links){
    if(!graph[link.toNode].visited){
      if(graph[link.toNode].explored == true)
        findMin(graph, link.toNode, minLink);
      if(link.weight < minLink.weight && graph[link.toNode].explored == false){
        graph[minLink.toNode].explored = false;
        minLink = link;
        graph[link.toNode].explored = true;
      }
    }
  }  
}
Link findMin(vector<Node>& graph, int nodeId){
  Link minLink(0, 0, INT_MAX);
  findMin(graph, nodeId, minLink);
  resetGraph(graph);
  return minLink;
}
void sumWeight(vector<Node>& graph, int nodeId, int& acc){
  graph[nodeId].visited = true;

  for(Link link : graph[nodeId].links){
    if(!graph[link.toNode].visited){
      acc += link.weight;
      sumWeight(graph, link.toNode, acc);
    }
  }
}
int sumWeight(vector<Node>& graph, int nodeId){
  int acc = 0;
  sumWeight(graph, nodeId, acc);
  resetGraph(graph);
  return acc;
}
void findGraph(vector<Node>& graph, int nodeId){
  Link minLink = findMin(graph, nodeId);
  if(minLink.weight == INT_MAX) return;
  findGraph(graph, nodeId);
}

int main(){
  ifstream fin("retele.in");
  ofstream fout("retele.out");

  int n; fin >> n;
  int m; fin >> m;
  vector<Node> graph(n + 1);

  int inNode1, inNode2, inWeight;
  while(fin >> inNode1 >> inNode2 >> inWeight){
    graph[inNode1].links.push_back(Link(inNode1, inNode2, inWeight));
    graph[inNode2].links.push_back(Link(inNode2, inNode1, inWeight));
  }


  graph[7].explored = true;
  cout << findMin(graph, 7).weight << endl;
  cout << findMin(graph, 7).weight<< endl;
  cout << findMin(graph, 7).weight<< endl;
  cout << findMin(graph, 7).weight<< endl;
  findGraph(graph, 7);
  cout << sumWeight(graph, 7);



  fin.close();
  fout.close();
  

  return 0;
}