class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(auto i = 0;i<board.size();i++){
            for(auto j = 0;j<board[0].size();j++){
                if(board[i][j] == 'X' && 
                   (i-1<0 || board[i-1][j] == '.') &&
                   (j-1<0 || board[i][j-1] == '.'))
                   ans++;
            }
        }
        return ans;
    }
};
