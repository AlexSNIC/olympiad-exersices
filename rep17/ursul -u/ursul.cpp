#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <deque>

using namespace std;
struct Poz{
  int x, y;
  Poz(int pozY, int pozX) : x(pozX), y(pozY) {};

  bool equals(Poz altPoz){
    if(x == altPoz.x && y == altPoz.y) return true;
    else return false;
  }
};

typedef vector<vector<int>> Matrix;
typedef deque<Poz> Queue;

void print(Matrix mat){
  for(auto vec : mat){
    for(auto val : vec){
      cout << setw(3) << val;
    }
    cout << endl;
  }
  cout << endl;
}

int getMatAt(Matrix mat, int pozY, int pozX){
  size_t size = mat.size();
  if(pozX < 0 || pozX >= size) return -1;
  else if(pozY < 0 || pozY >= size) return -1;
  else return mat.at(pozY).at(pozX);
}

Matrix bfs(const Matrix originalMat, Queue queue, int ticks = 1){
  Matrix mat = originalMat;
  vector<vector<bool>> visitedMat(mat.size(), vector<bool>(mat.size(), false));
  for(Poz poz : queue){
    visitedMat.at(poz.y).at(poz.x) = true;
  }
  int depth = 0;
  Poz threshold = queue.front();
  int tick = ticks - 1;
  while(!queue.empty()){
    Poz poz = queue.back(); queue.pop_back();
    int pozVal = getMatAt(mat, poz.y, poz.x);
    bool isPozValid = pozVal < 0? 0 : 1;

    if(isPozValid){
      mat.at(poz.y).at(poz.x) = depth;

      Poz topPoz = Poz(poz.y + 1, poz.x);
      Poz leftPoz = Poz(poz.y, poz.x - 1);
      Poz rightPoz = Poz(poz.y, poz.x + 1);
      Poz bottomPoz = Poz(poz.y - 1, poz.x);

      
      if(getMatAt(mat, topPoz.y, topPoz.x) == 0 && !visitedMat.at(topPoz.y).at(topPoz.x)) {
        queue.push_front(topPoz);
        visitedMat.at(topPoz.y).at(topPoz.x) = true;
      }
      if(getMatAt(mat, leftPoz.y, leftPoz.x) == 0 && !visitedMat.at(leftPoz.y).at(leftPoz.x)) {
        queue.push_front(leftPoz);
        visitedMat.at(leftPoz.y).at(leftPoz.x) = true;
      }
      if(getMatAt(mat, bottomPoz.y, bottomPoz.x) == 0 && !visitedMat.at(bottomPoz.y).at(bottomPoz.x)) {
        queue.push_front(bottomPoz);
        visitedMat.at(bottomPoz.y).at(bottomPoz.x) = true;
      }
      if(getMatAt(mat, rightPoz.y, rightPoz.x) == 0 && !visitedMat.at(rightPoz.y).at(rightPoz.x)) {
        queue.push_front(rightPoz);
        visitedMat.at(rightPoz.y).at(rightPoz.x) = true;
      }
    }

    if(poz.equals(threshold)){
      tick++;
      threshold = queue.front();
      if(tick == ticks){
        depth++;
        tick = 0;
      }
    }
  }

  return mat;
}

int solution(Matrix ogMat, Poz start, Poz end){
  int depth = max(ogMat.at(start.y).at(start.x), ogMat.at(end.y).at(end.x));

  Matrix mat(ogMat.size(), vector<int>(ogMat.size(), -1));
  while(true){

    for(int i = 0; i < mat.size(); i++){
      for(int j = 0; j < mat.size(); j++){
        if(ogMat.at(i).at(j) == -1){
          mat.at(i).at(j) = -1;
          continue;
        }
        mat.at(i).at(j) = (ogMat.at(i).at(j) >= depth ? 0 : -1);
      }
    }
    mat.at(end.y).at(end.x) = 0;
    Queue queue {start};
    Matrix resMat = bfs(mat, queue);
    if(resMat.at(end.y).at(end.x) > 0) break;
    depth--;
    if(depth <= 0) break;

  }
  return --depth;
}


int main(){
  ifstream fin("ursul.in");
  ofstream fout("ursul.out");

  int n, s; fin >> n >> s;
  Poz start(0, 0), end(0, 0);

  Matrix mat(n, vector<int>(n));
  Queue hivePositions;
  Queue bearPosition;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      char c; fin >> c;
      if(c == 'G') mat.at(i).at(j) = 0;
      else if(c == 'T') mat.at(i).at(j) = -1;
      else if(c == 'M') {
        mat.at(i).at(j) = 0;
        start.y = i;
        start.x = j;
        bearPosition.push_front(Poz(i, j));
      }
      else if(c == 'D') {
        mat.at(i).at(j) = -1;
        end.y = i;
        end.x = j;
      }
      else if(c == 'H') {
        mat.at(i).at(j) = 0;
        hivePositions.push_front(Poz(i, j));
      }
    }
  }

  Matrix bearBFS = bfs(mat, bearPosition, s);

  for(Poz poz : hivePositions){
    mat.at(poz.y).at(poz.x) = 0;
  }

  Matrix hiveBFS = bfs(mat, hivePositions);

  for(Poz poz : hivePositions){
    mat.at(poz.y).at(poz.x) = -1;
  }

  Matrix subMat = hiveBFS;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(mat.at(i).at(j) == -1){
        subMat.at(i).at(j) = -1;
        continue;
      }
      subMat.at(i).at(j) -= bearBFS.at(i).at(j);
    }
  }
  print(hiveBFS);
  print(bearBFS);
  print(subMat);

  int sol = solution(subMat, start, end);

  if(sol < 0){
    fout << "no solution";
    return 0;
  }
  cout << sol;



  fin.close();
  fout.close();
}
