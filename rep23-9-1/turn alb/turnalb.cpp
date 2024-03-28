#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>
#include <deque>

using namespace std;
int letterToNr(char letter){
  return letter - 'a';
}
int stringToNr(char nr){
  return nr - '0' - 1;
}

class Poz{
  public:
    int x, y;

    Poz(int yT, int xT) : x(xT), y(yT){};
  public:
    bool isEqualTo(Poz altPoz){
      bool isEqual = false;
      if(altPoz.x == x && altPoz.y == y){
        isEqual = true;
      }
      return isEqual;
    }
    bool isValid(){
      bool isValid = true;
      if(x < 0 || y < 0) isValid = false;
      if(x >= 8 || y >= 8) isValid = false;
      return isValid;
    }
  
};
void printMat(vector<vector<int>> mat){
  for(vector<int> vec : mat){
    for(int val : vec) cout << setw(3) << val;
    cout << endl;
  }
}

int main(){
  ifstream fin("turnalb.in");
  ofstream fout("turnalb.out");
  
  string pozR, pozBP;
  fin >> pozBP >> pozR;

  Poz pozStart = Poz(stringToNr(pozR[1]), letterToNr(pozR[0]));
  Poz pozEnd = Poz(stringToNr(pozBP[1]), letterToNr(pozBP[0]));
  
  vector<vector<int>> mat(8, vector<int>(8, 99));
  mat.at(pozStart.y).at(pozStart.x) = 0;

  int n; fin >> n;
  string piece;
  while(fin >> piece){
    int pozX = letterToNr(piece[0]);
    int pozY = stringToNr(piece[1]);
    mat.at(pozY).at(pozX) = -1;
  }

  deque<Poz> queue {pozStart};
  Poz threshold {pozStart};

  int depth = 1;

  while(true){
    if(queue.empty()){
      depth = -1;
      break;
    }
    Poz poz = queue.back();
    queue.pop_back();

    if(poz.isEqualTo(pozEnd)){
      break;
    }
    bool answerFound = false;
    bool actions = true;
    if(!poz.isValid()) actions = false;
    else if(mat.at(poz.y).at(poz.x) == -1) actions = false;


    if(actions){

      for(int i = poz.x; i >= 0; i--){
        if(mat.at(poz.y).at(i) == -1) break;
        if(mat.at(poz.y).at(i) == 99){
          queue.push_front(Poz(poz.y, i));
          mat.at(poz.y).at(i) = depth;
        }
        if(Poz(poz.y, i).isEqualTo(pozEnd)) answerFound = true;
      }
      for(int i = poz.x; i < 8; i++){
        if(mat.at(poz.y).at(i) == -1) break;
        if(mat.at(poz.y).at(i) == 99){
          queue.push_front(Poz(poz.y, i));
          mat.at(poz.y).at(i) = depth;
        }
        if(Poz(poz.y, i).isEqualTo(pozEnd)) answerFound = true;
      }
      for(int i = poz.y; i >= 0; i--){
        if(mat.at(i).at(poz.x) == -1) break;
        if(mat.at(i).at(poz.x) == 99){
          queue.push_front(Poz(i, poz.x));
          mat.at(i).at(poz.x) = depth;
        }
        if(Poz(i, poz.x).isEqualTo(pozEnd)) answerFound = true;
      }
      for(int i = poz.y; i < 8; i++){
        if(mat.at(i).at(poz.x) == -1) break;
        if(mat.at(i).at(poz.x) == 99){
          queue.push_front(Poz(i, poz.x));
          mat.at(i).at(poz.x) = depth;
        }
        if(Poz(i, poz.x).isEqualTo(pozEnd)) answerFound = true;
      }
    }

    if(poz.isEqualTo(threshold)){
      threshold = queue.front();
      depth++;
    }
    if(answerFound)break;
  }
  
  if(depth == -1){
    cout << "no solution" << endl;
    return 0;
  }
  cout << mat.at(pozEnd.y).at(pozEnd.x);


  fin.close();
  fout.close();

  return 0;
}