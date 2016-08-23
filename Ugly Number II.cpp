class Solution {
public:
    int nthUglyNumber(int n) {
        queue<long long> q2,q3,q5;
        q2.push(2);
        q3.push(3);
        q5.push(5);
        long long k=2;
        long long i=0;
        long long res=1;
        while(i<n-1){
            res=k;
            if(k==q2.front()){
                q2.pop();
                q2.push(2*k);
                q3.push(3*k);
                q5.push(5*k);
            }else{
                if(k==q3.front()){
                    q3.pop();
                    q3.push(3*k);
                    q5.push(5*k);
                }else{
                    q5.pop();
                    q5.push(5*k);
                }
            }
            k=min(min(q3.front(),q5.front()),q2.front());
            i++;
        }
        return res;
    }
};
