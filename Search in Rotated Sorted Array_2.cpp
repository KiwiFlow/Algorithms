class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right){
            // cout << "left: " << left << "  right: " << right <<endl;
            
            
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) return mid;
            
            if(left == right) return -1;
            
            if(nums[mid] >= nums[left] && nums[mid] <= nums[right]){
                if(nums[mid] > target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
                continue;
            }
            
            if(nums[mid] >= nums[left] && nums[mid] >= nums[right]){
                if(nums[left] > target){
                    left = mid + 1;
                }else{
                    if(nums[mid] < target){
                        left = mid + 1;
                    }else{
                        right = mid - 1;
                    }
                    
                }
                continue;
            }
            
            if(nums[mid] <= nums[left] && nums[mid] <= nums[right]){
                if(nums[right] < target){
                    right = mid - 1;
                }else{
                    if(nums[mid] < target){
                        left = mid + 1;
                    }else{
                        right = mid - 1;
                    }
                    
                }
            }
        }
        return -1;
    }
};
