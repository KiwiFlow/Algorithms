class Solution {
public:
    int add(int i,int j,const vector<vector<int>> &grid){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size()){
            return grid[i][j]?0:1;
        }else{
            return 1;
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    ans+=add(i-1,j,grid);
                    ans+=add(i+1,j,grid);
                    ans+=add(i,j-1,grid);
                    ans+=add(i,j+1,grid);
                }
            }
        }
        return ans;
    }
};
