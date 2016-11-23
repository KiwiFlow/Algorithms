class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int ans = 0;
        for(int j=0;j<g.size()&&i<s.size();j++){
            while(i<s.size() && s[i]<g[j]) i++;
            if(i<s.size()){
                ans++;
                i++;
            }
        }
        return ans;
    }
};
