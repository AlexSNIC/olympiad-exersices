#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;
int letterToNr(char letter){
  return letter - 'a';
}
int stringToNr(char nr){
  return nr - '0';
}


int main(){
  ifstream fin("turnalb.in");
  ofstream fout("turnalb.out");
  const int tableSize = 9;
  vector<vector<int>> board(10, vector<int>(10)); 
  
  string piece; fin >> piece;
  pair<int, int> goal = {stringToNr(piece[1]) + 1, letterToNr(piece[0]) + 1};
  fin >> piece;
  pair<int, int> poz = {stringToNr(piece[1]) + 1, letterToNr(piece[0]) + 1};
  int n; fin >> n;
  for(int i = 0; i < n; i++){
    board.at(stringToNr(piece[1])).at(letterToNr(piece[0])) =  -1;
  }

  deque<pair<int, int>> queue;
  pair<int, int> threshold;
  int depth = 1;
  bool goalReached = false;
  while(!queue.empty() && !goalReached){
    poz = queue.back();
    queue.pop_back();
    int i = 1;
    while(true){
      if(poz == goal){
        goalReached = true;
        break;
      }
      if(poz.first + i <= tableSize && poz.second <= tableSize)
        if(board.at(poz.first + i).at(poz.second) == 0){
          board.at(poz.first + i).at(poz.second) = depth;
          queue.push_front(make_pair(poz.first + i, poz.second))
        }
      if(poz.first - i <= tableSize && poz.second <= tableSize)
        if(board.at(poz.first - i).at(poz.second) == 0){
          board.at(poz.first - i).at(poz.second) = depth;
          queue.push_front(make_pair(poz.first - i, poz.second))
        }
      if(poz.first - i <= tableSize && poz.second <= tableSize)
      if(board.at(poz.first).at(poz.second + i) == 0){
        board.at(poz.first).at(poz.second + i) = depth;
        queue.push_front(make_pair(poz.first, poz.second + i))
      }
      if(board.at(poz.first).at(poz.second - i) == 0){
        board.at(poz.first).at(poz.second - i) = depth;
        queue.push_front(make_pair(poz.first, poz.second - i))
      }
      i++;
    }
  }

  fin.close();
  fout.close();

  return 0;
}