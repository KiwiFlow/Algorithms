class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }
        int a_1 = nums[0],a_2 = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<a_1){
                a_1=nums[i];
            }else{
                if(nums[i]>a_1 && nums[i]<a_2){
                    a_2=nums[i];
                }else{
                    if(nums[i]>a_2){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
