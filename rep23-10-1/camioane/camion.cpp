#include <iostream>
#include <fstream>
using namespace std;

const int nmax  = 100001;
int temps[nmax];
int n;
int moves;

void printTemps(){
  for(int i = 0; i < n; i++){
    cout << temps[i] << " ";
  }
  cout << endl;
}

int findInterval(int poz){
  int max = 0;
  if(temps[poz] > 0)
    for(int i = poz; i < n; i++){
      if(temps[i] > 0) max++;
      else break;
    }
  if(temps[poz] < 0)
    for(int i = poz; i < n; i++){
      if(temps[i] < 0) max++;
      else break;
    }
  return max;
}
void changeInterval(int interval, int poz, bool pozitive){
  for(int i = 0; i < interval; i++){
    if(pozitive) temps[poz + i]--;
    else temps[poz + i]++;
  }
}

void findMoves(int poz){
  if(poz >= n)return;
  if(temps[poz] == 0){
    findMoves(poz + 1);
    return;
  }
  int interval = findInterval(poz);
  changeInterval(interval, poz, temps[poz] > 0);
  moves++;
  findMoves(poz);
}


int main(){

  ifstream fin("camion.in");
  ofstream fout("camion.out");
  
  fin >> n;

  for(int i = 0; i < n; i++){
    fin >> temps[i];
  }
  for(int i = 0; i < n; i++){
    int temp; fin >> temp;
    temps[i] -= temp;
  }
  findMoves(0);
  cout << moves;


  fin.close();
  fout.close();

  return 0;
}