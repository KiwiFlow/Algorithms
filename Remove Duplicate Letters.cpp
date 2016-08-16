class Solution {
public:
    string removeDuplicateLetters(string s) {
        int L = s.size();
        int *r = (int*)malloc(sizeof(int)*L);
        for(int i=L-1;i>=0;i--){
            if(i==L-1){
                r[i]=1<<(s[i]-'a');
            }else{
                r[i] = r[i+1]|(1<<(s[i]-'a'));
            }
        }
        stack<char> k;
        int ff=0;
        for(int i=0;i<s.size();i++){
            if(!(ff&(1<<(s[i]-'a')))){
                while(!k.empty() && s[i]<=k.top() && (r[i]&(1<<(k.top()-'a')))){
                    ff = ff &(~(1<<(k.top()-'a')));
                    k.pop();
                }
                k.push(s[i]);
                ff = ff|(1<<(s[i]-'a'));
            }
        }
        char *ret = new char[k.size()+1];
        ret[k.size()]=0;
        int j=k.size()-1;
        while(!k.empty()){
            ret[j]=k.top();
            k.pop();
            j-=1;
        }
        string rr(ret,ret+strlen(ret));
        return rr;
    }
};
