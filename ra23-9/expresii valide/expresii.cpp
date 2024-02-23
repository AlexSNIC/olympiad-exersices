#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void findSol(string& p, ofstream& fout){
  int square{}, round{}, curly{};
  bool isValid = true;

  vector<char> stack {p.at(0)};
  int index = 1;
  while(true){
    if(index == p.length()){
      break;
    }

    char val = p.at(index);
    if(val == ')'){
      if(stack.back() != '(')
        isValid = false;
      round++;
      stack.pop_back();
    }
    else if(val == ']'){
      if(stack.back() != '[')
        isValid = false;
      square++;
      stack.pop_back();
    }
    else if(val == '}'){
      if(stack.back() != '{')
        isValid = false;
      curly++;
      stack.pop_back();
    }
    else stack.push_back(p.at(index));

    index++;
    if(!isValid) break;
  }
  
  if(!stack.empty()) isValid = false;
  cout << (isValid? "DA" : "NU");
  if(isValid){
    cout << " (" << round << ") [" << square << "] {" << curly << "}";
  }
  cout << endl;
}

int main(){

  ifstream fin("expresii.in");
  ofstream fout("expresii.out");
  
  int n; fin >> n;
  string p;
  while(fin >> p){
    findSol(p, fout);
  }

  fin.close();
  fout.close();

  return 0;
}