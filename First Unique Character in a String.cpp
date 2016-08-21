class Solution {
public:
    int firstUniqChar(string s) {
        int L = s.size();
        int *r = (int*)malloc(sizeof(int)*L);
        for(int i=L-1;i>=0;i--){
            if(i==L-1){
                r[i]=0;
            }else{
                r[i] = r[i+1]|(1<<(s[i+1]-'a'));
            }
        }
        int ff=0;//记录前面出现过的字符
        for(int i=0;i<L;i++){
            if(!(ff&(1<<(s[i]-'a')))){
                if(!(r[i]&(1<<(s[i]-'a')))){
                    return i;
                }
                ff = ff|(1<<(s[i]-'a'));
            }
        }
        return -1;
    }
};
