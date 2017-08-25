class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(s.empty()) return 0;
		int hash_map[256];
		memset(hash_map,-1,256*sizeof(int));
        
        
        int res = 1;
        int can_begin = 0; //candidate begin
        
        
        for(int i = 0; i < s.size() ; i++){
            if(hash_map[s[i]] < can_begin){
                //该字符出现的位置在can_begin之前
                res = max(res,i-can_begin+1);
            }else{
                //can_begin到头了,换一个can_begin
                res = max(res,i-can_begin);
                can_begin = hash_map[s[i]] + 1;
            }
            hash_map[s[i]] = i;
        }
        
        return res;
        
        
        
        
        
        
// 		int maxVal=1;
// 		int result=0;//以i-1为结尾下标的longer substring
// 		for(int i=0;i<s.size();i++)
// 		{
// 			if(hash_map[(unsigned char)s[i]]<i-result)
// 			{
// 				result++;
// 			}else
// 			{
// 				result=i-hash_map[(unsigned char)s[i]];
// 			}
			
// 			hash_map[(unsigned char)s[i]]=i;
// 			maxVal=max(maxVal,result);
// 		}
// 		return maxVal;
    }
};
