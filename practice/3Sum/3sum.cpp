#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <tuple>

typedef std::tuple<int, int, int> int_tpl;

class Solution {
public:
    int sortedTuple(int a, int b, int c){
      int arr[3] = {a, b, c};
      std::sort(arr, arr + 3);
      return std::make_tuple(arr[0], arr[1], arr[2]);
    }

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
      std::unordered_set<int_tpl> set;
      std::sort(nums.begin(), nums.end());

      auto target = nums.begin();
      auto start = target + 1;
      auto end = nums.end() - 1;

      auto next = [target, start, end] () {
        target++;
        start = target + 1;
        end = nums.end() - 1;
      }

      while(target != nums.end() - 4){
        if(*start + *end == *target){
          set
        }
      }
    }
    void log(std::vector<std::vector<int>> sol){
      std::cout << "[";
      int i = 0;
      for(std::vector<int>& vec : sol){
        std::cout << "[";
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
  const int testcase[] = {0, 1, 2, -1 , -2, -4}; // -4 -2 -1 0 1 2


}