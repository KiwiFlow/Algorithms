class Solution {
public:
    int minimumOperations(string &s) {
       int ans = 0;
      for(int i=0;i<s.size()/2;i++){
        ans += abs(s[i]-s[s.size()-1-i]);
      }
      return ans;
    }
};
