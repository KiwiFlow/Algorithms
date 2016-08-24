/* MLE
class So {
public:
    bool exist(vector<vector<char> > &board, string word) {
		bool *used= new bool[board.size()*board[0].size()];
        for(int i=0;i<board.size();i++)
		{
			for(int j=0;j<board[0].size();j++)
			{
				memset(used,false,board.size()*board[0].size());
				if(board[i][j]==word[0] && exist(board,word,0,i,j,used))
				{
					return true;
				}
			}
		}
		return false;
    }
private:
	bool exist(const vector<vector<char> > &board,const string &word,int index,int i,int j,bool *used)
	{
		int row=board.size(),column=board[0].size();
		used[i*column+j]=true;
		if(index == word.size()-1)
		{
			return true;
		}
		//left
		if( i>=0 && i<row && j-1>=0 && j-1 < column && used[i*column+j-1]==false && word[index+1]==board[i][j-1])
		{
			//deep copy
			bool *leftState=new bool[row*column];
			for(int iter=0;iter<row*column;iter++)
			{
				leftState[iter]=used[iter];
			}
			if(exist(board,word,index+1,i,j-1,leftState))
				return true;
		}
		//right
		if( i>=0 && i<row && j+1>=0 && j+1 < column && used[i*column+j+1]==false && word[index+1]==board[i][j+1])
		{
			//deep copy
			bool *rightState=new bool[row*column];
			for(int iter=0;iter<row*column;iter++)
			{
				rightState[iter]=used[iter];
			}
			if(exist(board,word,index+1,i,j+1,rightState))
				return true;
		}
		//up
		if( i-1>=0 && i-1<row && j>=0 && j < column && used[(i-1)*column+j]==false && word[index+1]==board[i-1][j])
		{
			//deep copy
			bool *upState=new bool[row*column];
			for(int iter=0;iter<row*column;iter++)
			{
				upState[iter]=used[iter];
			}
			if(exist(board,word,index+1,i-1,j,upState))
				return true;
		}
		//down
		if( i+1>=0 && i+1<row && j>=0 && j < column && used[(i+1)*column+j]==false && word[index+1]==board[i+1][j])
		{
			//deep copy
			bool *downState=new bool[row*column];
			for(int iter=0;iter<row*column;iter++)
			{
				downState[iter]=used[iter];
			}
			if(exist(board,word,index+1,i+1,j,downState))
				return true;
		}
		return false;
	}
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        So so;
        vector<string> res;
        vector<string>::iterator end_unique =  unique(words.begin(), words.end()); 
        words.erase(end_unique, words.end());
        for(int i=0;i!=words.size();i++){
            if(so.exist(board,words[i])){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
*/
