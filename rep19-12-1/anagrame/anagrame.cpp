#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<long long> letterVal 
          {71231, 458903, 149041, 104023, 353437, 552079, 947094, 20175, 76504, 312003,
          12314, 3157, 770747, 43214, 55315, 257041, 140415, 6123, 204123, 540547,
          140005, 29457, 540804, 80332, 514143, 12031};

long long getVal(char c){
  return letterVal.at(c - 'a');
}

int main(){

  ifstream fin("anagrame.in");
  ofstream fout("anagrame.out");

  string s, key; fin >> s >> key;
  vector<long long> values(s.length() - key.length() + 1);
  size_t keyLen = key.length();
  long long keyVal = 0, currentVal = 0;
  for(char c : key){
    keyVal += getVal(c);
  }
  for(int i = 0; i < keyLen - 1; i++){
    currentVal += getVal(s.at(i));
  }
  for(int i = 0; i <= s.length() - keyLen; i++){
    currentVal += getVal(s.at(i + keyLen - 1));
    values.at(i) = currentVal;
    currentVal -= getVal(s.at(i));
  }
  int index = -1;
  for(int i = 0; i < values.size(); i++){
    if(values.at(i) == keyVal){
      index = i;
      break;
    }
  }
  fout << index;

  fin.close();
  fout.close();

  return 0;
}