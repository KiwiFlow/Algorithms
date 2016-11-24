class Solution {
public:
    int arrangeCoins(int n) {
        long long n2 = 2LL*n;
        long long a = (long long)sqrt(n2);
        return (a*(a+1)<=n2)?a:a-1;
    }
};
