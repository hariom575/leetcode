class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(nums.size(),INT_MAX-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                int next=i+j;
                if(next>=n) continue;
                dp[next]=min(dp[next],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};