#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(){

  ifstream fin("luni.in");
  ofstream fout("luni.out");
  
  char crt; fin >> crt;
  short target; fin >> target;
  int n; fin >> n;

  vector<string> months(12);
  string month; short temp;
  while(fin >> month >> temp){
    if(crt == '>'){
      if(temp > target){
        months.push_back(month);
      }
    }
    else if(crt == '<'){
      if(temp < target){
        months.push_back(month);
      }
    }
  }

  vector<string> allMonths {"ianuarie", "februarie", "martie", "aprilie", "mai", "iunie",
        "iulie", "august", "septembrie", "octombrie", "noiembrie", "decembrie"};
  
  for(string m : allMonths){
    bool hasMonth = (find(months.begin(), months.end(), m) == months.end()? false : true);
    if(hasMonth){
      fout << m << endl;
    }
  }

  fin.close();
  fout.close();

  return 0;
}