class Solution {
public:
    int missingNumber(const vector<int> &a) {
      int sum = 0;
      for(int i=0;i<a.size();i++){
        sum+=a[i];
      }
      return (a.size()+2)*(a.size()+1)/2-sum;
    }
};
