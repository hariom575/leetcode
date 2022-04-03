class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        if(nums.size()==1) return;
        while((i>=0)&&(nums[i]>=nums[i+1])) i--;
        if(i<0){
            sort(nums.begin(),nums.end());
            return;
        }
        else{
            int j=nums.size()-1;
            while(nums[i]>=nums[j]) j--;
            swap(nums[i],nums[j]);
}
        sort(nums.begin()+(i+1),nums.end());
        return;
    }
};