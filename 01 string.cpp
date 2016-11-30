/*
Given a string consists of only characters 0 and 1. You can only delete characters from it.

You want to change it into a string contains only alternating 0 and 1. Namely no Two consecutive characters are the same.

How many characters do you need to delete at least?
*/

class Solution {
public:
    int leastDeletion(string &s) {
      int ans = 0;
      char pre = s[0];
      for(int i=1;i<s.size();i++){
        if(s[i]==pre){
          ans++;
        }else{
          pre = s[i];
        }
      }
      return ans;
    }
};
