class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<char>> dp(matrix);
        int ret=0;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }else{
                    if(i-1<0 || j-1<0){
                        dp[i][j]=1;
                        ret=max(ret,1);
                    }else{
                        dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                        ret=max(ret,dp[i][j]*dp[i][j]);
                    }
                }
            }
        }
        return ret;
    }
};
