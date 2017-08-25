class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> dict;
		vector<int> ret;
		for(int i=0;i<numbers.size();i++)
		{
            if(dict.count(target-numbers[i])){
                ret.push_back(dict[target-numbers[i]]);
                ret.push_back(i);
            }
			dict[numbers[i]]=i;
		}
		return ret;
    }
};
