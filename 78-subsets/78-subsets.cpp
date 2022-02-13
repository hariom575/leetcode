class Solution {
public:
    int dp[1<<10+1][11];
    void helper(int idx,int n,int mask,vector<int>&nums,vector<int>cur,vector<vector<int>>&ans){
        if(idx==n){
            sort(cur.begin(),cur.end());
            ans.push_back(cur);
            return;
        }
        if(dp[mask][idx]) return;
        dp[mask][idx]=1;
        for(int i=idx;i<n;i++){
            if(mask&(1<<i)) continue;
            cur.push_back(nums[i]);
            helper(idx+1,n,(mask|1<<i),nums,cur,ans);
            cur.pop_back();
            helper(idx+1,n,mask,nums,cur,ans);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    memset(dp,0,sizeof(dp));
    vector<vector<int>>ans;
    vector<int>cur;
    int n=nums.size();
    helper(0,n,0,nums,cur,ans);
        return ans;
    }
};