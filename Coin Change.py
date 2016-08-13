class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        vector<int> r(amount+1,0);
        for(int i=0;i<r.size();i++){
            for(int j=0;j<coins.size();j++){
                if(i==coins[j]){
                    r[i]=1;
                    break;
                }else{
                    if(i-coins[j]>0 && r[i-coins[j]]!=0){
                        if(r[i]==0){
                            r[i]=r[i-coins[j]]+1;
                        }else{
                            r[i]=min(r[i-coins[j]]+1,r[i]);
                        }
                    }
                }
            }
        }
        return r[amount]==0?-1:r[amount];
    }
};
