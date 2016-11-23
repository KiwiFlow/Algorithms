class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median = nums[nums.size()/2];
        int ans = 0;
        for(auto &val:nums){
            ans += abs(median-val);
        }
        return ans;
    }
};
