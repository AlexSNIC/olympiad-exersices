#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int start, int end){
  if(end <= start) return;
  int i = start - 1;

  for(int j = start; j < end; j++){
    if(arr[j] < arr[end]){
      swap(arr[++i], arr[j]);
    }
  }
  swap(arr[++i], arr[end]);

  quickSort(arr, start, i - 1);
  quickSort(arr, i + 1, end);
};

int main(){

  ifstream fin("file.in");
  ofstream fout("file.out");
  
  int n; fin >> n;
  vector<int> arr;
  arr.reserve(n);

  for(int i = 0; i < n; i++){
    int val; fin >> val;
    arr.push_back(val);
  }
  for(int i = 0; i < n; i++){
    fout << arr[i] << " ";
  }
  fout << endl;


  quickSort(arr, 0, n-1);

  for(int i = 0; i < n; i++){
    fout << arr[i] << " ";
  }
  fin.close();
  fout.close();

  return 0;
}