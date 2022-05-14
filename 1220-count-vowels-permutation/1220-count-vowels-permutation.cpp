class Solution {
public:
    int countVowelPermutation(int n) {
     vector<vector<long long>>dp(n,vector<long long>(5,1));
        int mod=1e9+7;
        for(int i=n-2;i>=0;i--){
            dp[i][0]=(dp[i+1][1])%mod;
            dp[i][1]=(dp[i+1][0]%mod+dp[i+1][2]%mod)%mod;
            dp[i][2]=(dp[i+1][0]%mod+dp[i+1][1]%mod+dp[i+1][3]%mod+dp[i+1][4]%mod)%mod;
            dp[i][3]=(dp[i+1][2]%mod+dp[i+1][4]%mod)%mod;
            dp[i][4]=(dp[i+1][0])%mod;
        }
        return (dp[0][0]%mod+dp[0][1]%mod+dp[0][2]%mod+dp[0][3]%mod+dp[0][4]%mod)%mod;
    }
};