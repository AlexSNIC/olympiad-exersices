#include <iostream>
#include <fstream>
#include <deque>

using namespace std;


int main(){

  ifstream fin("bacterii.in");
  ofstream fout("bacterii.out");

  int n, lifetime, totalTime;
  fin >> n >> lifetime >> totalTime;

  long long total = n;
  deque<long long> rounds {0};

  for(int i = 1; i < totalTime; i++){
    int bornThisGeneration = total;
    total += rounds[0];
    rounds.push_front(bornThisGeneration);

    if(i >= lifetime){
      total -= rounds.back();
      rounds.pop_back();
    }
    // cout << endl << i << endl;
    // cout << "total: " << total << endl;
    // cout << "btg: " << bornThisGeneration << endl;
    // cout << "rounds: "; for(int val : rounds) cout << val << " "; cout << endl;
  }

  fout << total;
  

  fin.close();
  fout.close();

  return 0;
}




// #include <iostream>
// #include <fstream>

// using namespace std;

// int bacterii(bool isBig, int lifespan, int timeRemaining, int originalLifespan){
//   if(timeRemaining == 0) return 0;
//   if(lifespan == 0) return -1;
//   int sum = 0;
//   if(!isBig){
//     sum = bacterii(true, lifespan - 1, timeRemaining - 1, originalLifespan); 
//   }
//   else {
//     sum++;
//     sum += bacterii(false, originalLifespan, timeRemaining - 1, originalLifespan);
//     sum += bacterii(true, lifespan - 1, timeRemaining - 1, originalLifespan);
//   }
//   return sum;
// }

// int main(){
//   ifstream fin("bacterii.in");
//   ofstream fout("bacterii.out");

//   int n, lifespan, time;
//   fin >> n >> lifespan >> time;
//   long long alive = n * bacterii(false, lifespan, time, lifespan);
//   fout << alive;


//   fin.close();
//   fout.close();
// }