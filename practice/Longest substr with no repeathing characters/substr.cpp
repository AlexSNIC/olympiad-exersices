#include <iostream>
#include <unordered_set>
#include <string>
class Solution {
  private: 
  public:
    int lengthOfLongestSubstring(std::string s){
      auto startIt = s.begin();
      auto endIt = s.begin();
      std::unordered_set<char> set;

      int length = 0;
      int maxLength = 0; 

      while(true){
        const char currentValue = *startIt;

        if(startIt == endIt || set.find(currentValue) == set.end()){
          set.insert(currentValue);
          startIt++;
          length++;
          maxLength = std::max(maxLength, length);
        }
        else{
          do{
            set.erase(*endIt);
            endIt++;
            length--;
          }
          while(*endIt != currentValue);
        }
        if(startIt == s.end()) break;
      }
      return maxLength;
    }
} solution;

int main(){
  std::cout << solution.lengthOfLongestSubstring("qwertyuiopasdfgthjklzxcvtbnm");
  
}


/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/