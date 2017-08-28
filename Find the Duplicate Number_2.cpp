class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        
        while(left <= right){
            if(left == right) return left;
            
            int mid = left + (right - left) / 2;
            
            int lhs = 0;
            
            for(auto x : nums){
                if(x >= left && x <= mid){
                    lhs++;
                }
            }
            
            if(lhs > mid - left + 1){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
    }
};
