class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it=lower_bound(nums.begin(),nums.end(),target);
        if(it==nums.end() || *it!=target){
            return {-1,-1};
        }
        auto it1=upper_bound(nums.begin(),nums.end(),target);
        it1--;
        int idx1=it-nums.begin();
        int idx2=it1-nums.begin();
        return {idx1,idx2};
    }
};