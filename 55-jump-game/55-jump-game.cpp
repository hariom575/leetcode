class Solution {
public:
    bool canJump(vector<int>& nums) {
    if(nums[0]==0 and nums.size()==1) return true;
            if(nums[0]==0) return false;
        int step= nums[0];
        int maxjump=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==n-1)
                return true;
            maxjump=max(maxjump,i+nums[i]);
             if(step==0){
                 if(maxjump<=i)
                    return false;
                 step=maxjump-i;
             }
        
        step--;
        }
        return false;
    }
};