#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

struct Poz{
  int x = 1;
  int y = 1;
};

int main(){
  ifstream fin("robot.in");
  ofstream fout("robot.out");

  int n; fin >> n; --n; // -1 unitate la pornire
  bool toTopRight = true;
  Poz poz;

  while(n){
    if(toTopRight && poz.y == 1){
      poz.x++;
      toTopRight = false;
    }
    else if(!toTopRight && poz.x == 1){
      poz.y++;
      toTopRight = true;
    }
    else if(toTopRight){
      poz.x++;
      poz.y--;
    }
    else if(!toTopRight){
      poz.x--;
      poz.y++;
    }

    n--;
  }
  fout << poz.y << endl << poz.x;

  fin.close();
  fout.close();

  return 0;

}