class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         int i = 0, j = 0, sz = nums.size() ;
        vector<int> res; deque<int> dq ;
        
        while(j<sz) // sliding window start 
        {
            while(!dq.empty() && nums[j] > dq.back()){ dq.pop_back() ;} // vakues left to max are of no use
            dq.push_back(nums[j]) ; //push each value
            
            if(j-i+1 < k){ j++ ;} // reach the window size
            else{
                res.push_back(dq.front()) ; // get answre
                if(nums[i] == dq.front()){ dq.pop_front() ;} // remove calc related to window first elem by checking it in the queue
                i++ ; j++ ; //slide the window
            }
        }
        
        return res ;
    }
	
};