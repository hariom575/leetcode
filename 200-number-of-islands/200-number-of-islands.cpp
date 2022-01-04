class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    bool isvalid(int x,int y,int m ,int n,vector<vector<char>>&grid){
        if(x<0 || y<0 || x>=m || y>=n || grid[x][y]=='0')  return false;
        return true;
    }
    void dfs(int x,int y,int m,int n,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
        int nwx=x+dx[i];
        int nwy=y+dy[i];
          if(isvalid(nwx,nwy,m,n,grid) and !vis[nwx][nwy]){
              dfs(nwx,nwy,m,n,vis,grid);
          }
}
}
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]=='1' and !vis[i][j]){
                   cnt++;
                  dfs(i,j,m,n,vis,grid);
              }
            }
        }
        return cnt;
    }
};