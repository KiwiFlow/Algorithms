/*TLE
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int M=matrix.size();
        int N=matrix[0].size();
        for(int j=0;j<N;j++){
            for(int i=0;i<M;i++){
                if(i>=1){
                    matrix[i][j]=matrix[i-1][j]+matrix[i][j];
                }
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(j>=1){
                    matrix[i][j]=matrix[i][j-1]+matrix[i][j];
                }
            }
        }
        int res=INT_MIN;
        //一维化
        for(int i=0;i<M*N;i++){
            for(int j=i;j<M*N;j++){
                int a=j/N,b=j%N;
                int _m = i/N,_n=i%N;
                if(a>=_m && b>=_n){
                    int c1=0,c2=0,c3=0;
                    if(_n>=1){
                        c1=matrix[a][_n-1];
                    }
                    if(_m>=1){
                        c2=matrix[_m-1][b];
                    }
                    if(_m>=1 && _n>=1){
                        c3=matrix[_m-1][_n-1];
                    }
                    int c = matrix[a][b]-c1-c2+c3;
                    if(c<=k){
                        res=max(res,c);
                    }
                }
            }
        }
        return res;
    }
};*/
