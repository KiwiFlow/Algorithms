class Solution {
public:
    int change(int x, int y) {
      int z = x^y;
      int ans = 0;
      while(z){
        if(z&1) ans++;
        z = z>>1;
      }
      return ans;	
    }
};
