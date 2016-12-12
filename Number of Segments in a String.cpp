class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for(int i=0;i<s.size();){
            if(s[i]!=' '){
                while(i<s.size() && s[i]!=' ') i++;
                res++;
            }else{
                i++;
            }
        }
        return res;
    }
};
