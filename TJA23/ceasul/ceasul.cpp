#include <iostream>
#include <fstream>
using namespace std;


int main(){

  ifstream fin("ceasul.in");
  ofstream fout("ceasul.out");

  if(!fin.is_open() || !fout.is_open()){
    return 404;
  }

  int hour, mins;
  fin >> hour >> mins;
  int addHour, addMins;
  fin >> addHour >>addMins;

  hour += addHour;
  mins += addMins;
  
  hour += mins / 60;
  mins %= 60;
  hour %= 24;

  if(hour < 10)fout << 0;
  fout << hour << " ";
  if(mins < 10)fout << 0;
  fout << mins;

  fin.close();
  fout.close();

  return 0;
}