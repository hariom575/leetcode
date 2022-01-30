class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        k=n-k;
        reverse(nums.begin(),nums.begin()+k);
        for(int i:nums) cout<<i;
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};