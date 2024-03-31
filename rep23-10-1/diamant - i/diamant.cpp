#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;
typedef vector<vector<bool>> Mat;


bool isValid(int pozY, int pozX, int sizeY, int sizeX){
  bool valid = true;
  if(pozX < 0 || pozX >= sizeX) valid = false;
  if(pozY < 0 || pozY >= sizeY) valid = false;

  return valid;
}
bool isDiamond(Mat mat, int r, int pozY, int pozX, int sizeY, int sizeX){
  bool outerValid = true;
  bool innerValid = true;
  int bottomPozY = pozY + 2*(r - 1);
  for(int i = 0; i < r; i++){
    if(!isValid(pozY + i, pozX + i, sizeY, sizeX) || mat.at(pozY + i).at(pozX + i) != 0){
      outerValid = false;
      break;
    }
    // if(!isValid(pozY + i, pozX - i, sizeY, sizeX) || mat.at(pozY + i).at(pozX - i) != 0){
    //   outerValid = false;
    //   break;
    // }
    if(!isValid(bottomPozY - i, pozX + i, sizeY, sizeX) || mat.at(bottomPozY - i).at(pozX + i) != 0){
      outerValid = false;
      break;
    }
    if(!isValid(bottomPozY - i, pozX - i, sizeY, sizeX) || mat.at(bottomPozY - i).at(pozX - i) != 0){
      outerValid = false;
      break;
    }

    int topRowStartY = pozY + i;
    int bottomRowStartY = bottomPozY - i;
    int rowStartX = pozX - i + 1;
    int sumRequirement = i == 0? 0 : i * 2 - 1;
    int topRowSum = 0, bottomRowSum = 0;
    for(int j = 0; j < sumRequirement; j++){
      topRowSum += mat.at(topRowStartY).at(rowStartX + j);
      bottomRowSum += mat.at(bottomRowStartY).at(rowStartX + j);
    }

    if(topRowSum != sumRequirement || bottomRowSum != sumRequirement){
      innerValid = false;
    }
  }

  return outerValid && innerValid;
}
int getRadius(Mat& mat, int pozY, int pozX, int sizeY, int sizeX){
  int r = 1;
  int altY = pozY + 1, altX = pozX - 1;
  while(isValid(altY, altX, sizeY, sizeX) && mat.at(altY).at(altX) == 0){
    r++;
    if(isValid(altY + 1, altX + 1, sizeY, sizeX) && mat.at(altY + 1).at(altX + 1) == 0){
      break;
    }
    altY += 1;
    altX -= 1;
  }

  return r;
}

int main(){

  ifstream fin("diamant.in");
  ofstream fout("diamant.out");

  int sizeX, sizeY;
  fin >> sizeY >> sizeX;
  Mat mat(sizeY, vector<bool>(sizeX, 0));
  for(int i = 0; i < sizeY; i++){
    for(int j = 0; j < sizeX; j++){
      char c; fin >> c;
      bool val = c == '.'? 1 : 0;
      mat.at(i).at(j) = val;
    }
  }
  
  int sum = 0;
  for(int i = 0; i < sizeY; i++){
    for(int j = 0; j < sizeX; j++){
      if(mat.at(i).at(j) == 0){
        int radius = getRadius(mat, i, j, sizeY, sizeX);
        if(radius > 1)
          sum += isDiamond(mat, radius, i, j, sizeY, sizeX);
      }
    }
  }
  
  fout << endl << sum;
  fin.close();
  fout.close();

  return 0;
}