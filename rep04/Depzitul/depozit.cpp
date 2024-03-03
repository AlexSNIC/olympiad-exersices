#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <deque>
#include <iomanip>
#include <algorithm>

using namespace std;

void print(vector<vector<short>> mat){
  for(vector<short> vec: mat){
    for(short val : vec){
      cout << setw(3) << val;
    }
    cout << endl;
  }
  cout << endl;
}

void findPath(vector<vector<short>>& mat, int toX, int toY, ofstream& fout){
  vector<pair<short, short>> ans;
  int pozX = toX, pozY = toY;
  ans.push_back(make_pair(pozX, pozY));
  int level = mat.at(pozX).at(pozY);
  while(true){
    if(pozX <= 0 || pozX >= mat.size()) continue;
    else if(pozY <= 0 || pozY >= mat.at(0).size()) continue;
    if(mat.at(pozX).at(pozY) == 1) break;
    
    if(mat.at(pozX + 1).at(pozY) == level - 1)pozX++;
    else if(mat.at(pozX).at(pozY + 1) == level - 1)pozY++;
    else if(mat.at(pozX - 1).at(pozY) == level - 1)pozX--;
    else if(mat.at(pozX).at(pozY - 1) == level - 1)pozY--;
    ans.push_back(make_pair(pozX, pozY));
    level--;
  }

  reverse(ans.begin(), ans.end());
  for(pair<short, short> poz : ans){
    fout << poz.first << " " << poz.second << endl;
  }
}

int main(){

  ifstream fin("depozit.in");
  ofstream fout("depozit.out");
  
  int sizeX, sizeY;
  fin >> sizeX >> sizeY;
  int fromX, fromY, toX, toY;
  fin >> fromX >> fromY >> toX >> toY;
  int k; fin >> k;
  sizeX++; sizeY++;
  vector<vector<short>> rad(sizeX + 1, vector<short>(sizeY + 1, 0));
  short radX, radY;
  while(fin >> radX >> radY)
    rad.at(radX).at(radY) = -1;
  
  pair<short, short> from = make_pair(fromX, fromY);
  pair<short, short> to = make_pair(toX, toY);
  deque<pair<short, short>> queue {from};
  pair<short, short> threshold = from;
  int depth = 1;

  while(!queue.empty()){
    pair<short, short> poz = queue.back();
    queue.pop_back();

    bool skipCheck = false;
    if(poz.first <= 0 || poz.first >= sizeX) skipCheck = true;
    else if(poz.second <= 0 || poz.second >= sizeY) skipCheck = true;
    else if(rad.at(poz.first).at(poz.second) != 0) skipCheck = true;
 
    if(!skipCheck){
      rad.at(poz.first).at(poz.second) = depth;   
      if(poz.first == toX && poz.second == toY) break;
      queue.push_front(make_pair(poz.first + 1, poz.second));
      queue.push_front(make_pair(poz.first, poz.second + 1));
      queue.push_front(make_pair(poz.first - 1, poz.second));
      queue.push_front(make_pair(poz.first, poz.second - 1));
    }

    if(threshold == poz){
      threshold = queue.front();
      depth++;
    }
  }

  fout << --depth << endl;
  findPath(rad, toX, toY, fout);
  fin.close();
  fout.close();

  return 0;
}