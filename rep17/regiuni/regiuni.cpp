#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

struct Node{
  int id;
  int visited = false;
  vector<int> neighborsId;
};

int main(){
  ifstream fin("regiuni.in");
  ofstream fout("regiuni.out");

  int n; fin >> n; n++;
  vector<Node> nodes(n);
  for(int i = 0; i < n; i++){
    nodes.at(i).id = i;
  }
  int from, to;
  while(fin >> from >> to){
    nodes.at(from).neighborsId.push_back(to);
  }

  deque<int> queue;
  queue.push_back(0);
  queue.push_back(1);
  int k = 0;

  while(!queue.empty()){
    Node& node = nodes.at(queue.front());
    queue.pop_front();
    node.visited = true;

    for(int neighborId : node.neighborsId){
      if(!nodes.at(neighborId).visited){
        queue.push_back(neighborId);
      }
      else{
        cout << node.id << " " << nodes.at(neighborId).id << endl;
        k++;
      }
    }
  }
  --k; // removing node path 0 -> 0
  cout << k;
  

  fin.close();
  fout.close();
  

  return 0;
}