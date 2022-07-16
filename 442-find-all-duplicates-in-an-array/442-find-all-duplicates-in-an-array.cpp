class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int t = abs(nums[i]);
            if(nums[t-1] > 0) nums[t-1] *= (-1);
            else if(nums[t-1] < 0) ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};