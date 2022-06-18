class Solution {
public:
    int dp[205][205];
    int helper(int n,int row,int col,vector<vector<int>>&t){
        if(col>row)
            return 0;
        if(row==n-1)
            return dp[row][col]=t[row][col];
        int ans=0;
        if(dp[row][col]!=-1) return dp[row][col];
        ans=t[row][col]+min(helper(n,row+1,col,t),helper(n,row+1,col+1,t));
        return dp[row][col]=ans;
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        memset(dp,-1,sizeof(dp));
        return helper(n,0,0,t);
        }
};