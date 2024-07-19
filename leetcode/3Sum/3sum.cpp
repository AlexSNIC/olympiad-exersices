#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
      std::sort(nums.begin(), nums.end());      
    }
    void log(std::vector<std::vector<int>> sol){
      std::cout << "["
      int i = 0;
      for(vector<int>& vec : sol){
        std::cout << "["
        std::cout << vec[0] << ",";
        std::cout << vec[1] << ",";
        std::cout << vec[2];
        if(i != sol.size() - 1)
          std::cout << "],";
        else std::cout << "]";
        i++;
      }
      std::cout << ']';
    }
} solution;

int main(){
  const int[] testcase = {0, 1, 2, -1 , -2, -4};



}