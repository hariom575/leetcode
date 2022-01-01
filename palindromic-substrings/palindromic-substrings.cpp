class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)
            dp[i][i]=1;
        for(int l=2;l<=n;l++){
            for(int i=1;i<=n-l+1;i++){
                int j=i+l-1;
                if(l==2){
                    if(s[i-1]==s[j-1])
                        dp[i][j]=1;
                }
                else if(s[i-1]==s[j-1] and dp[i+1][j-1]==1)
                {
                    dp[i][j]=1;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                ans+=dp[i][j];
        }
        return ans;
    }
};