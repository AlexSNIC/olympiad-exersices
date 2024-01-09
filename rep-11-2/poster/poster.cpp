#include <iostream>
#include <fstream>
#define nmax 100000
using namespace std;

int count = 0;



void findPath(string str, int n, int x, char target, bool been2){
  if(x >= n) return;
  if(str[x] == target){
    char tempTarget = target;
    bool tempBeen2 = been2;
    switch(tempTarget){
      case 'O':
        tempTarget = 'R';
        break;
      case 'R':
        tempTarget = 'I';
        break;
      case 'I':
        tempTarget = '2';
        break;
      case '2':
        if(tempBeen2)
          tempTarget = '3';
        else{
          tempBeen2 = true;
          tempTarget = '0';
        }
        break;
      case '0':
        tempTarget = '2';
        break;
      case '3':
        count++;
        return;
    }
    
    findPath(str, n, x + 1, tempTarget, tempBeen2);
  }
  findPath(str, n, x + 1, target, been2);
}

int main(){

  ifstream fin("poster.in");
  ofstream fout("poster.out");

  string str;
  fin >> str;
  int n = str.length();
  
  findPath(str, n, 0, 'O', false);
  cout << endl << count;


  fin.close();
  fout.close();

  return 0;
}