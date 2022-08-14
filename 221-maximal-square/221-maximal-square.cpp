class Solution {
public:
    int vis[301][301];
    int dp[301][301];
    int res=0;
    int helper(int row,int col,int n,int m,vector<vector<char>>&matrix){
        if(row>=n || col>=m || row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int ans1=helper(row+1,col,n,m,matrix);
        int ans2=helper(row,col+1,n,m,matrix);
        int ans3=helper(row+1,col+1,n,m,matrix);
        int ans=0;
        if(matrix[row][col]=='1'){
            ans=min(ans1,min(ans2,ans3))+1;
        }
        res=max(res,ans*ans);
        return dp[row][col]=ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp,-1,sizeof(dp));
        helper(0,0,matrix.size(),matrix[0].size(),matrix);
        return res;
    }
};