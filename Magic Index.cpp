class Solution {
public:
    int magicIndex(vector<int> &A) {
      for(int i=0;i<A.size();i++){
        if(A[i]==i) return i;
      }
      return -1;	
    }
};
