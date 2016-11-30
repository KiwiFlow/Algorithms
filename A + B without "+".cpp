/*
Write a function to calculate the result of integer A plus integer B using BIT OPERATIONS without ‘+’.
*/

class Solution {
public:
    int aPlusb(int a,int b) {
        if(b == 0)
            return a;
        return aPlusb( a^b, (a & b) << 1);
    }
};
