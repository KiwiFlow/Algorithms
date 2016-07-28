class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return "";
        if(strs.size()==1) return strs[0];
        int ret=0;
        string ans;
        bool isContinue=true;
        while(true)
        {
            for(int i=0;i<strs.size()-1;)
            {
                if(ret<strs[i].length() && ret<strs[i+1].length() && strs[i][ret]==strs[i+1][ret])
                {
                    i++;
                }
                else
                {
                    isContinue=false;
					break;
                }
            }
			if(isContinue)
			{
			    ans.push_back(strs[0][ret]);
				ret++;
			}
			else
			    break;
        }
        return ans;
    }
};
