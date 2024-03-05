#include <iostream>

#include "ghici.h"
// intervalMin() - returneaza valoarea cea mai mica a intervalului
// intervalMax() - returneaza valoarea cea mai mare a intervalului
// SeAflaIn(int minInt, int maxInt) - returneaza true daca numarul se afla in interval, altfel false.
// NumarulGhicit(int nr) - afiseaza daca raspunsul e corect sau nu

using namespace std;

void findN(int minInt, int maxInt){
  if(maxInt <= minInt) {
    NumarulGhicit(maxInt);
    return;
  }

  int middle = (minInt + maxInt) / 2;
  bool left = SeAflaIn(minInt, middle);
  if(left){
    findN(minInt, middle);
  }
  else{
    findN(middle + 1, maxInt);
  }
}

int main(){
  int minInt = intervalMin();
  int maxInt = intervalMax();

  findN(minInt, maxInt);

}