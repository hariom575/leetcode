class Solution {
    public int firstMissingPositive(int[] nums) {
        
        int len = nums.length;
        
        for(int i = 0 ; i < len; i++){
		   //use while instead of if , the swaped number may not be put on the right plce, but if you use if, it will have no chance to put on the right place
            while(nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i] ){
                swap(nums, nums[i] - 1, i);
            }
        }
        
    
        for(int i = 0; i < len; i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        
        
        return len + 1;
    }
    
    
    public void swap ( int[] nums, int i, int j ){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}