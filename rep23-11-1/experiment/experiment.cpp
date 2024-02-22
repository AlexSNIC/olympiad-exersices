#include <iostream>
#include <fstream>
#define nmax 5000
using namespace std;

short arr[nmax];

void print(int n){
  for(int i = 0; i < n; i++){
    cout << arr[i] << ' ';
  }
  cout << endl;
}


void quickSort(int start, int end){
  if(end <= start) return;
  int i = start - 1;

  for(int j = start; j < end; j++)
    if(arr[j] < arr[end])
      swap(arr[++i], arr[j]);
  swap(arr[++i], arr[end]);

  quickSort(start, i - 1);
  quickSort(i + 1, end);
}

int main(){

  ifstream fin("experiment.in");
  ofstream fout("experiment.out");
  int n; fin >> n;
  for(int i = 0; i < n; i++){
    fin >> arr[i];
  }
  quickSort(0, n - 1);
  bool isSuccessful = true;
  int dist = 0;
  for(int i = 0; i < n - 1; i++){
    if(arr[i] + 1 != arr[i + 1])
      isSuccessful = false;
    if(arr[i] != arr[i + 1]) dist++;
    else dist--;
  }
  if(arr[n - 2] != arr[n - 1]) dist++;

  fout << (isSuccessful? "DA" : "NU") << endl << (isSuccessful? arr[n - 1] : dist);


  fin.close();
  fout.close();

  return 0;
}