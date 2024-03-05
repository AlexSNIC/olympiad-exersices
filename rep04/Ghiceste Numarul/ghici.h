#include <iostream>

int n = 1;
int minimumValue = 1;
int maximumValue = 32000;
int nCounter = 0;

bool SeAflaIn(int a, int b){
  nCounter++;
  return a <= n && b >= n? true : false;
}
int intervalMin(){
  return minimumValue;
}
int intervalMax(){
  return maximumValue;
}
void NumarulGhicit(int nr){
  if(n == nr){
    std::cout << "Ai ghicit! (" << nCounter << " intrebari)";
  }
  else{
    std::cout << "Nu ai ghicit... (" << nCounter << " intrebari)";
  }
}