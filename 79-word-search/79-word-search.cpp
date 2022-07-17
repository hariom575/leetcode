class Solution {
public:
   bool Search(vector<vector<char>>& board, string &word,int index, int row, int col)
{       
    if(index>= word.size())
        return true;
    
    if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index] )
        return false;
    
    char temp = board[row][col];
    board[row][col] = '.';
    
    bool check = Search(board, word, index+1, row+1, col) || Search(board, word, index+1, row-1, col) ||   Search(board, word, index+1, row , col-1 ) || Search(board, word, index+1, row , col+1) ;
    
    board[row][col] = temp;
    return check;
    
}
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i< board.size() ; i++)
    {
        for(int j = 0 ; j< board[0].size() ; j++)
        {
            if(Search(board, word, 0 , i, j))   
             return true; 
        }
    }
    return false;
    
}
};