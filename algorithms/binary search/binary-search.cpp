#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int binarySearch(vector<char>& arr, char target, int start, int end, bool ascending = true){
  if(end < start) return CHAR_MIN;

  int middle = (start + end) / 2;
  if(arr[middle] == target) return middle;

  if(ascending) return arr[middle] > target?
  binarySearch(arr, target, start, middle - 1):
  binarySearch(arr, target, middle + 1, end);

  else return arr[middle] < target?
  binarySearch(arr, target, start, middle - 1):
  binarySearch(arr, target, middle + 1, end);
  
}



int main(){

  ifstream fin("file.in");
  ofstream fout("file.out");

  int n; fin >> n;
  char target; fin >> target;

  vector<char> arr;
  for(int i = 0; i < n; i++){
    char val; fin >> val;
    arr.push_back(val);
  }

  int index = binarySearch(arr, target, 0, n - 1, true) + 1;
  if(index != CHAR_MIN + 1) fout << index;
  else fout << "not found";

  fin.close();
  fout.close();

  return 0;
}