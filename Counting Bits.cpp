class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> vec(num+1,0);
        vec[0]=0;
        for(int m=0;;m++){
            int left = pow(2,m),right = pow(2,m+1)-1;
            int j=left;////当前正在计算的数字
            for(;j<=num && j<=right;j++){
                vec[j]=1+vec[j-left];
            }
            if(j>num){
                return vec;
            }
        }
    }
};
/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/
