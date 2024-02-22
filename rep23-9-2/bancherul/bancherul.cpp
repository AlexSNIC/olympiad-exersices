#include <iostream>
#include <fstream>
#include <string>
using namespace std;




int main(){

  ifstream fin("bancherul.in");
  ofstream fout("bancherul.out");

  int n; fin >> n;
  string colection[n];
  string colectionSorted[n];

  for(int i = 0; i < n; i++){
    fin >> colection[i];
  }
  for(int i = 0; i < n; i++){
    cout << colection[i] << " ";
  }
  cout << endl;
  
  for(int i = 0; i < n; i++){
    string max = "!";
    int maxIndex;

    for(int j = 0; j < n; j++){
      if(colection[j] == "100"){
        max = colection[j];
        maxIndex = j;
        break;
      }
      
      bool changedM = false;
      string maxC = max;
      if(max[1] == '\0'){
        max = max + max;
        changedM = true;
      }
      
      bool changedC = false;
      string colC = colection[j];
      if(colection[j][1] == '\0'){
        colection[j] = colection[j] + colection[j];
        changedC = true;
      }

      if(max < colection[j]){
        if(changedC){
          colection[j] = colC;
        }
        max = colection[j];
        maxIndex = j;
      }
      else {
        colection[j] = colC;
        max = maxC;
      }
    }
    colection[maxIndex] = "!";

    colectionSorted[i] = max;
  }


  
  for(int i = 0; i < n; i++){
    cout << colectionSorted[i] << " ";
  }

  fin.close();
  fout.close();
  return 0;
}