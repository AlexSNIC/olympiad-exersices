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
    

    int i = 0;
    while(true){
      if(poz == goal){
        goalReached = true;
      }
    }
    i = 0;
  }

  fin.close();
  fout.close();

  return 0;
}