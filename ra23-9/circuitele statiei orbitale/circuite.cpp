#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findEc(string& ec){
  int operations = 0;
  int i = 0;
  while(true){
    if(i >= ec.length() - 1) break;

    if(ec.at(i) == '!'){
      operations++;
      ec.erase(i, 1);
      if(ec.at(i) == '0')
        ec.at(i) = '1';
      else ec.at(i) = '0';
      continue;
    }

    i++;
  }
  i = 0;
  
  while(true){
    if(i >= ec.length() - 1) break;

    if(ec.at(i + 1) == '&'){
      operations++;

      string compare1 = {ec.at(i)};
      string compare2 = {ec.at(i + 3)};
      bool val = (stoi(compare1) && stoi(compare2));
      ec.erase(i, 3); 
      ec.at(i) = to_string(val).at(0);
      
      continue;
    }
    i++;
  }
  i = 0;
  while(true){
    if(i >= ec.length() - 1) break;

    if(ec.at(i + 1) == '|'){
      operations++;

      string compare1 = {ec.at(i)};
      string compare2 = {ec.at(i + 3)};
      bool val = (stoi(compare1) || stoi(compare2));
      ec.erase(i, 3); 
      ec.at(i) = to_string(val).at(0);

      continue;
    }
    i++;
  }
  return operations;
}

int main(){

  ifstream fin("circuite.in");
  ofstream fout("circuite.out");
  
  int n; fin >> n;
  string ec;
  while(fin >> ec){
    int oper = findEc(ec);
    fout << ec << " (" << oper  << ")" << endl;
  }

  fin.close();
  fout.close();

  return 0;
}