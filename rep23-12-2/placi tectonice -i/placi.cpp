#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


void calc(vector<int>& mounts, int from, int to, int x){
  for(int i = from; i <= to; i++){
    mounts.at(i) += x;
  }
}
int getTemp(vector<int>& mounts, int nextIsHigherMultiple, int nextIsLowerMultiple){
  int temp = 0;
  for(int i = 1; i < mounts.size(); i++){
    int crt = mounts.at(i) > mounts.at(i - 1)? -nextIsHigherMultiple : nextIsLowerMultiple; 
    temp += crt * abs(mounts.at(i) - mounts.at(i - 1));
    // cout << crt << " x abs(" << mounts.at(i) << " + " << mounts.at(i - 1) << ")" << endl;
  }

  return temp;
}

int main(){
  ifstream fin("placi.in");
  ofstream fout("placi.out");

  int nMounts, days, nextIsHigherMultiple, nextIsLowerMultiple;
  fin >> nMounts >> days >> nextIsHigherMultiple >> nextIsLowerMultiple;
  nMounts++;
  vector<int> mounts;
  for(int i = 0; i < nMounts; i++){
    int mountVal; fin >> mountVal;

    mounts.push_back(mountVal);
  }

  for(int day = 0 ; day < days; day++){
    int from, to, val; fin >> from >> to >> val;
    calc(mounts, from, to, val);
    int temp = getTemp(mounts, nextIsHigherMultiple, nextIsLowerMultiple);

    cout << temp << endl;
  }


  fin.close();
  fout.close();
}