#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

struct Node{
	int id;
	int depth = -1;
	
	vector<int> neighborsId; 
};

int maxPath = INT_MIN;

void bfs(vector<Node>& nodes, vector<int> queue, int k){
	if(queue.empty()) return;
	
	vector<int> nextQueue;
	if(k == 1)for(int nodeId : queue)cout << nodeId	<< endl;
	while(!queue.empty()){
		Node& node = nodes.at(queue.back()); queue.pop_back();
		if(node.depth != -1) continue;
		node.depth = k;
		
		for(int neighborId : node.neighborsId){
			if(nodes.at(neighborId).depth == -1)	
				nextQueue.push_back(neighborId);
		}
	}	
	
	bfs(nodes, nextQueue, ++k);	
}

int main()
{
	ifstream fin("cale.in");
	ofstream fout("cale.out");	
	
	int n, m; fin >> n >> m;
	
	vector<Node> nodes(n);
	
	for(int i = 0; i < n; i++){
		nodes.at(i).id = i;
	}
	for(int i = 0; i < m; i++){
		int from, to; fin >> from >> to;
		
		nodes.at(from).neighborsId.push_back(to);
		nodes.at(to).neighborsId.push_back(from);
	}
	
	vector<int> startQueue {0};
	
	bfs(nodes, startQueue, 0);
	
	for(int i = 0; i < n; i++){
		cout << "node" <<	i <<	": " <<	nodes.at(i).depth << endl	;
	}
	
	
	fin.close();
	fout.close();
	
	return 0;
}