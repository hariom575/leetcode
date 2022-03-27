class Solution {
public:
    vector<vector<int>>dp;
   inline int helper(vector<vector<int>>&piles,int idx,int n,int k){
        if(dp[idx][k]!=-1) return dp[idx][k];
        if(idx==n){
            return 0;
        }
        int ans=helper(piles,idx+1,n,k);
        int sum=0;
        for(int t=1;t<=k&&t<=piles[idx].size();++t){
            sum+=piles[idx][t-1];
            ans=max(ans,helper(piles,idx+1,n,k-t)+sum);
            }
        return dp[idx][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        dp=vector<vector<int>>(n+1,vector<int>(k+1,-1));
        return helper(piles,0,n,k);
    }
};