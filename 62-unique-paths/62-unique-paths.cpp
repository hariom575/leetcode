class Solution {
public:
    int mod=2e9+7;
    int uniquePaths(int m, int n) {
      vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
            }
        }
        return dp[m-1][n-1]%mod;
    }
};