class Solution {
public:
    int count(int num){
        int ans = 0;
        while(num){
            ans++;
            num &= (num-1);
        }
        return ans;
    }
    
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i = 0;i <= num;i++){
            ans.push_back(count(i));
        }
        return ans;
    }
};
