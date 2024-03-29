#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<vector<bool>> Mat;

void printMat(Mat mat){
  for(auto vec : mat){
    for(auto val : vec){
      cout << val << " ";
    }
    cout << endl;
  }
}

bool isValid(int sizeY, int sizeX, int pozY, int pozX){
  bool isValid = true;
  if(pozX < 0 || pozX >= sizeX)isValid = false;
  if(pozY < 0 || pozY >= sizeY)isValid = false;

  return isValid;
}

int getBottom(Mat mat, int pozY, int pozX, int sizeY, int sizeX){
  int k = 0;
  int crtY = 1, crtX = -1;

  while(isValid(sizeY, sizeX, pozY, pozX) && mat.at(pozY).at(pozX)){
    int rowSum = 0;
    for(int i = 0; i < 2*k + 1; i++){
      if(isValid(sizeY, sizeX, pozY, pozX + i) && mat.at(pozY).at(pozX + i) == true){
        rowSum++;
      }
    }
    if(rowSum != 2*k + 1) break;
    k++;
    pozY += crtY;
    pozX += crtX;
  }
  return --k;
}
int getTop(Mat mat, int pozY, int pozX, int sizeY, int sizeX){
  int k = 0;
  int crtY = -1, crtX = -1;

  while(isValid(sizeY, sizeX, pozY, pozX) && mat.at(pozY).at(pozX)){
    int rowSum = 0;
    for(int i = 0; i < 2*k + 1; i++){
      if(isValid(sizeY, sizeX, pozY, pozX + i) && mat.at(pozY).at(pozX + i) == true){
        rowSum++;
      }
    }
    if(rowSum != 2*k + 1) break;
    k++;
    pozY += crtY;
    pozX += crtX;
  }
  return --k;
}
int getRight(Mat mat, int pozY, int pozX, int sizeY, int sizeX){
  int k = 0;
  int crtY = -1, crtX = 1;

  while(isValid(sizeY, sizeX, pozY, pozX) && mat.at(pozY).at(pozX)){
    int rowSum = 0;
    for(int i = 0; i < 2*k + 1; i++){
      if(isValid(sizeY, sizeX, pozY + i, pozX) && mat.at(pozY + i).at(pozX) == true){
        rowSum++;
      }
    }
    if(rowSum != 2*k + 1) break;
    k++;
    pozY += crtY;
    pozX += crtX;
  }
  return --k;
}
int getLeft(Mat mat, int pozY, int pozX, int sizeY, int sizeX){
  int k = 0;
  int crtY = -1, crtX = -1;

  while(isValid(sizeY, sizeX, pozY, pozX) && mat.at(pozY).at(pozX)){
    int rowSum = 0;
    for(int i = 0; i < 2*k + 1; i++){
      if(isValid(sizeY, sizeX, pozY + i, pozX) && mat.at(pozY + i).at(pozX) == true){
        rowSum++;
      }
    }
    if(rowSum != 2*k + 1) break;
    k++;
    pozY += crtY;
    pozX += crtX;
  }
  return --k;
}

int getTriangles(Mat mat, int pozY, int pozX, int sizeY, int sizeX){
  int sum = 0;
  sum += getBottom(mat, pozY, pozX, sizeY, sizeX);
  sum += getTop(mat, pozY, pozX, sizeY, sizeX);
  sum += getRight(mat, pozY, pozX, sizeY, sizeX);
  sum += getLeft(mat, pozY, pozX, sizeY, sizeX);
  

  return sum;
}

int main(){

  ifstream fin("piramida.in");
  ofstream fout("piramida.out");
  
  int sizeX, sizeY; fin >> sizeY >> sizeX;
  Mat mat(sizeY, vector<bool>(sizeX));

  for(int i = 0; i < sizeY; i++){
    for(int j = 0; j < sizeX; j++){
      char k; fin >> k;
      mat.at(i).at(j) = k - '0';
    }
  }
  printMat(mat);
  int sum = 0;
  for(int i = 0; i < sizeY; i++){
    for(int j = 0; j < sizeX; j++){
      if(mat.at(i).at(j) == 1){
        sum += getTriangles(mat, i, j, sizeY, sizeX);
      }
    }
  }

  cout << sum;


  fin.close();
  fout.close();

  return 0;
}