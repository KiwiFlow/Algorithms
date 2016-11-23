class Solution {
public:
    int thirdMax(vector<int>& nums) {
        list<int> ans;
        for(auto &val :nums){
            for(auto it = ans.begin();;it++){
                if(it == ans.end()){
                    ans.insert(it,val);
                    break;
                }
                if(val == *it){
                    break;
                }else{
                    if(val > *it){
                        ans.insert(it,val);
                        break;
                    }
                }
            }
            while(ans.size()>3) ans.pop_back();
        }
        if(ans.size()<3){
            return *ans.begin();
        }else{
            auto it = ans.begin();
            it++;
            it++;
            return *it;
        }
    }
};
