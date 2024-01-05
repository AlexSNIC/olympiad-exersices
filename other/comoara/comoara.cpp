#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

class Poz{
  private:
  const float deg45 = 3.141592/4;

  public:
    float x = 0, y = 0;

    void move(int dir, int steps){
      switch(dir){
        case 1: 
        y += steps;
        break;

        case 3:
        x += steps;
        break;

        case 5:
        y -= steps;
        break;
        
        case 7:
        x -= steps;
        break;

        case 2:
        x += steps * sin(deg45);
        y += steps * sin(deg45);
        break;

        case 4:
        x += steps * sin(deg45);
        y -= steps * sin(deg45);
        break;

        case 6:
        x -= steps * sin(deg45);
        y -= steps * sin(deg45);
        break;

        case 8:
        x -= steps * sin(deg45);
        y += steps * sin(deg45);
        break;
      }
    }
};

int main(){

  ifstream fin("comoara.in");
  ofstream fout("comoara.out");
  
  int n; fin >> n;
  Poz poz;
  for(int i = 0; i < n; i++){
    int dir, steps;
    fin >> dir >> steps;

    poz.move(dir, steps);
  }
  
  fout << setprecision(3) << fixed << poz.x << " ";
  fout << setprecision(3) << fixed << poz.y << endl;

  fin.close();
  fout.close();
  return 0;
}