/*class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        for(int i=0;i+p.size()<=s.size();i++){
            if(isAnagrams(s.substr(i,p.size()),p)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool isAnagrams(string s,const string &p){
        map<char,int> chars;
        for(auto &v:s){
            chars[v]++;
        }
        for(auto &v:p){
            if(chars.count(v)){
                chars[v]--;
                if(chars[v]==0){
                    chars.erase(v);
                }
            }else{
                return false;
            }
        }
        return chars.empty();
    }
};*/

/*class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        for(int i=0;i+p.size()<=s.size();i++){
            if(isAnagrams(s.substr(i,p.size()),p)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool isAnagrams(string s,const string &p){
        int mark[26] = {0};
        int chars[26] = {0};
        for(auto &v:s){
            chars[v-'a']++;
        }
        for(auto &v:p){
            if(chars[v-'a']){
                chars[v-'a']--;
            }else{
                return false;
            }
        }
        return !memcmp(mark,chars,sizeof(mark));
        
    }
};*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        char marks[26] = {0};
        for(auto &v:p){
            marks[v-'a']++;
        }
        char chars[26] = {0};
        int i=0;
        for(;i<p.size();i++){
            chars[s[i]-'a']++;
        }
        if(!memcmp(marks,chars,sizeof(marks))){
            ans.push_back(0);
        }
        for(;i<s.size();i++){
            chars[s[i]-'a']++;
            chars[s[i-p.size()]-'a']--;
            if(!memcmp(marks,chars,sizeof(marks)))
                ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};
