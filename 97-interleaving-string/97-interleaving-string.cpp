class Solution {
public:
    bool helper(string s1,string s2,string s3,int i,int j,int k,vector<vector<int>>&dp){
   if(k>=s3.size())
       return (i>=s1.size() and j>=s2.size());
    if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
     if((s3[k]==s1[i] and helper(s1,s2,s3,i+1,j,k+1,dp))||(s3[k]==s2[j] and helper(s1,s2,s3,i,j+1,k+1,dp)))
         ans=true;
        return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return helper(s1,s2,s3,0,0,0,dp);
    }
};