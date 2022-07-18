class Solution {
public:
    pair<int,int> p[8]={{1,0},{-1,0},{1,1},{-1,-1},{0,1},{0,-1},{1,-1},{-1,1}};
    int ans[25][25];
    void process(int x,int y,int n,int m,vector<vector<int>>& board){
         int cnt=0;
        for(int i=0;i<8;i++){
            int newx=x+p[i].first;
            int newy=y+p[i].second;
           if(newx<0 || newy<0 || newx>=n || newy>=m) continue;
           if(board[newx][newy]==1) cnt++;
            // cout<<newx<<" "<<newy<<" "<<board[newx][newy]<<endl;
        }
         // cout<<"#"<<x<<" "<<y<<" "<<cnt<<endl;
        ans[x][y]=board[x][y];
        if(board[x][y]==1 and cnt<2) ans[x][y]=0;
        if(board[x][y]==1 and cnt>3) ans[x][y]=0;
        if(board[x][y]==0 and cnt==3) ans[x][y]=1;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                process(i,j,n,m,board);
            }
        }
        for(int  i=0;i<n;i++){
            for(int j=0;j<m;j++) board[i][j]=ans[i][j];
            // cout<<endl;
        }
    }
};