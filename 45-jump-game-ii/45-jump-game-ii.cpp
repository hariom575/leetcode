class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        int maxreach=0;
        int reach=0;
        if(n==1)
            return 0;
        for(int i=0;i<n-1;i++){
     if(i+nums[i]>maxreach)
maxreach=i+nums[i];
            if(i==reach){
                reach=maxreach;
                jump++;
}
        }
        return jump;

    }
};