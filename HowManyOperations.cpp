/*
Suppose you start from x = 0.

In each step you can operate on x by either of the 2 operations:

(1) x = x * 2

(2) x = x + 1

Given an integer n. How many operations at least to change x into n?
*/
class Solution {
public:
    int howManyOperations(int n) {
      if(n==0) return 0;
      if(n&1){
        return 1+howManyOperations(n-1);
      }else{
        return 1+howManyOperations(n/2);
      }
    }
};
