class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<dp.size();i++){
            int k=INT_MAX;
            for(int j=floor(sqrt(i));j>=1;j--){
                k = min(k,dp[i-j*j]+1);
            }
            dp[i] = k;
        }
        return dp[n];
    }
};
