/*
A frog can go up 1, 2, 3, …n stairs at each step. How many ways can it go up n-stairs?
*/

class Solution {
public:
    long howManyWays(int n) {
        return 1L<<(n-1);
    }
};
