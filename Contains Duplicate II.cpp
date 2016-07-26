class Solution {
public:
   bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> record;
        for(int i=0;i<nums.size();i++){
            if(record.find(nums[i]) == record.end()){
                record[nums[i]]=i;
            }else{
                if(i-record[nums[i]]<=k){
                    return true;
                }else{
                    record[nums[i]]=i;
                }
            }
        }
        return false;
    }
};
