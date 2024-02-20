#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream fin("formule.in");
  ofstream fout("formule.out");

  string exp; fin >> exp;
  bool isValid = true;
  if(exp[exp.length() - 1] == '+' || exp[exp.length() - 1] == '-' || exp[exp.length() - 1] == '*' || exp[exp.length() - 1] == '/') 
    isValid = false;

  exp = "1+" + exp;
  char prevType = 's';
  int parenthesesStack = 0;
  for(int i = 2; i < exp.length(); i++){
    if(exp[i] >= '0' && exp[i] <= '9'){
      if(prevType == 'c')
        isValid = false;
      prevType = 'n';
    }
    else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
      if(prevType == 's' || prevType == 'o')
        isValid = false;
      prevType = 's';
    }
    else if(exp[i] == '('){
      if(prevType == 'n' || prevType == 'c')
        isValid = false;
      parenthesesStack++;
      prevType = 'o';
    }
    else if(exp[i] == ')'){
      if(prevType == 's' || prevType == 'o')
        isValid = false;
      if(parenthesesStack <= 0)
        isValid = false;
      parenthesesStack--;
      
      prevType = 'c';
    }
    else isValid = false;
    if(!isValid) break;
  }
  if(parenthesesStack != 0) isValid = false;
  if(fin >> exp) isValid = false;

  fout << (isValid? "DA" : "NU");

  fin.close();
  fout.close();
}