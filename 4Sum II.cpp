class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        const int n = a.size();
        vector<int> e(n*n);
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			e[i*n+j] = c[i]+d[j];
    		}
    	}
    	sort(e.begin(),e.end());
    	int res = 0;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			res += (int)distance(lower_bound(e.begin(),e.end(),-(a[i]+b[j])),upper_bound(e.begin(),e.end(),-(a[i]+b[j])));
    		}
    	}
    	return res;
    }
};
