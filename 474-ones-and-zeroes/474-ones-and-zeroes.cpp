class Solution {
public:
    pair<int,int> count_zero_and_ones(string &s){
        int cnt=0;
        for(auto a:s){
            if(a=='0') cnt++;
        }
        return {cnt,s.size()-cnt};
    }
    int dp[601][101][101];
    int helper(vector<pair<int,int>>&str,int m,int n,int idx,int taken)
    {
        if(n<=0 and  m<=0){
            return 0;
        }
        if(idx>=str.size()){
            return 0;
        }
        if(m>=0 and n>=0 and dp[idx][m][n]!=-1){
            return dp[idx][m][n];
        }
        int ans1=0;
        int ans2=0;
        if(str[idx].first<=m and str[idx].second<=n){
            ans1=1+helper(str,m-str[idx].first,n-str[idx].second,idx+1,taken+1);
        }
        ans2=helper(str,m,n,idx+1,taken);
        return dp[idx][m][n]=max(ans1,ans2);
    }    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>str;
        memset(dp,-1,sizeof(dp));
        for(auto a:strs){
            str.push_back(count_zero_and_ones(a));
        }
        int ans=helper(str,m,n,0,0);
        return ans;
    }
};