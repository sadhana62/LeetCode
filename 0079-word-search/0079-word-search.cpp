class Solution {
public:
    bool dfs(int row,int col,vector<vector<char>>& board, string word, int i) {
      if (i == word.size()) return true;
      if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() 
            || board[row][col] != word[i]) {
            return false;
        }
      char temp = board[row][col];
      board[row][col] = '*';
      bool res = dfs(row+1,col,board,word,i+1) || dfs(row,col+1,board,word,i+1) || dfs(row-1,col,board,word,i+1) ||
      dfs(row,col-1,board,word,i+1);
      board[row][col] = temp;
      return res; 
    }
    bool exist(vector<vector<char>>& board, string word) {
       
       int n = board.size();
       int m = board[0].size();
       for (int i = 0;i<n;i++) {
        for (int j =0;j<m;j++) {
            if (dfs(i,j,board,word,0)){
                return true;
            }
        }
       }
       return false;
    }
};