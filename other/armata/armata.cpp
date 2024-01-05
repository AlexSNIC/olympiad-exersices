#include <iostream>
#include <fstream>
using namespace std;


int main(){

  ifstream fin("armata.in");
  ofstream fout("armata.out");

  int sizeX, sizeY, pozX, pozY;
  fin >> sizeX >> sizeY >> pozX >> pozY;

  int cad1, cad2, cad3, cad4;
  cad1 = (sizeX - pozX) * (pozY - 1);
  cad1 -= min((sizeX - pozX), (sizeY -pozY));

  cad2 = (pozX - 1) * (pozY - 1);
  cad2 -= min((pozX - 1), (sizeY - pozY));

  cad3 = (pozX - 1) * (sizeY - pozY);
  cad3 -= min((pozX - 1), (sizeY - pozY));

  cad4 = (sizeX - pozX) * (sizeY - pozY);
  cad4 -= min((sizeX - pozX), (sizeY - pozY));

  cad1 = cad1 < 0? 0 : cad1;
  cad2 = cad2 < 0? 0 : cad2;
  cad3 = cad3 < 0? 0 : cad3;
  cad4 = cad4 < 0? 0 : cad4;

  int sum = 0;
  if(pozX > 1 && pozY > 1) sum++;
  if(pozX > 1 && pozY < sizeY) sum++;
  if(pozX < sizeX && pozY > 1) sum++;
  if(pozX < sizeX && pozY < sizeY) sum++;
  if(pozX > 1) sum++;
  if(pozX < sizeX) sum++;
  if(pozY > 1) sum++;
  if(pozY < sizeY) sum++;

  sum += cad1 + cad2 + cad3 + cad4;
  
  cout << sum;
  
  fin.close();
  fout.close();
  return 0;
}