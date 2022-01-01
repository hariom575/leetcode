class Solution {
public:
int maxCoins(vector<int>& nums) {
    int n=nums.size();
    nums.resize(n+2);
    for(int i=n-1;i>=0;i--){
        nums[i+1]=nums[i];
    }
    nums[0]=1;
    nums[n+1]=1;
    vector<vector<long long>>dp(n+2,vector<long long>(n+2,0));
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            for(int k=i;k<=j;k++){
               dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
            }
        }
    }
    return dp[1][n];
}
};