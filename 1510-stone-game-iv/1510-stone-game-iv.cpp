class Solution {
public:
    vector<int>dp;
    bool helper(int n,vector<int>&sq){
        if(n<0) return true;
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        bool ans=false;
        for(auto a:sq){
            ans=ans| !helper(n-a,sq);
        }
        return dp[n]=ans;
    }
    bool winnerSquareGame(int n) {
        vector<int>sq;
        for(int i=1;i*i<=n;i++){
            sq.push_back(i*i);
        }
        dp=vector<int>(n+1,-1);
        dp[0]=false;
        return helper(n,sq);
    }
};