#include <iostream>
#include <fstream>
using namespace std;


int main(){

  ifstream fin("meteo.in");
  ofstream fout("meteo.out");

  int n;
  string crt;
  fin >> n >> crt;
  int tMin = 999, dMin = 0, tMax = -999, dMax = 0;
  for(int i = 0; i < n; i++){
    int day, temp;
    fin >> day >> temp;

    if(temp <= tMin){
      tMin = temp;
      dMin = day;
    }
    if(temp >= tMax){
      tMax = temp;
      dMax = day;
    }
  }
  if(crt == "min"){
    fout << dMin << '=' << tMin;
  }
  else if(crt == "max"){
    fout << dMax << '=' << tMax;
  }
  else if(crt == "minmax"){
    fout << dMin << '=' << tMin << ' ' << dMax << '=' << tMax;;
  }
  else{
    fout << "ERROR";
  }


  fin.close();
  fout.close();
  return 0;
}