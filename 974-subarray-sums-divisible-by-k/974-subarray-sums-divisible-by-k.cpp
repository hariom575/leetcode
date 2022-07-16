class Solution {
public:
     int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> dp;
        dp[0] = 1;
        int count=0;
        int sum=0;
        
        for(int i=0; i< nums.size(); i++){
            sum += nums[i];
            int reminder = sum % k;
            if(reminder <0){
                reminder += k;
            }
            if(dp.find(reminder) != dp.end()){
                count += dp[reminder];
            }
            dp[reminder]++;
        }
        return count;        
    }
};