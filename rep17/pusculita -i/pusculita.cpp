#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const vector<int> sums {0, 1, 5, 10, 25, 50};

int minSum = INT_MAX;
int findAll(int weight, int coins, int sum, int n = 5){
  if(weight < 0) return 0;
  else if (coins == 0 && weight != 0)return 0;
  else if (coins == 0 && weight == 0){
    if(sum < minSum)
      minSum = sum;
    return 1;
  }
  int paths = 0;
  if(n >= 1)paths += findAll(weight - 1, coins - 1, sum + 1, 1);
  if(n >= 2)paths += findAll(weight - 2, coins - 1, sum + 5, 2);
  if(n >= 3)paths += findAll(weight - 3, coins - 1, sum + 10, 3);
  if(n >= 4)paths += findAll(weight - 4, coins - 1, sum + 25, 4);
  if(n == 5)paths += findAll(weight - 5, coins - 1, sum + 50, 5);

  return paths;
}

int main(){
  ifstream fin("pusculita.in");
  ofstream fout("pusculita.out");
  int c, g; fin >> c >> g;

  int paths = findAll(g, c, 0);
  cout << minSum << ' ' << paths;

  fin.close();
  fout.close();
}