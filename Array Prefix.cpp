/*
Given a non-empty array of N integers A, please find the smallest integer P such that all the numbers in A are in the subarray A[0..P].
*/

class Solution {
public:
    int leastPrefix(vector<int> &A) {
      set<int> s;
      int ans = 0;
      for(int i=0;i<A.size();i++){
        int before = s.size();
        s.insert(A[i]);
        int after = s.size();
        if(after > before){
          ans = i;
        }
      }
      return ans;
    }
};
