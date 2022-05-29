class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // in this question we have to find the size of the subarray so it indicates that we have to work with indexes
        // now there is a base case like if nums array is sorted already than we will directly return 0
        
        if ( is_sorted(nums.begin() , nums.end()) ) return 0 ;
        
        // now the base case have been handled 
        // so now the next case is how we will find the length of the subarray which is sorted than whole array gets sorted 
        // the basic intutive idea here is lets see how many elements are not sorted properly ...
        // for this we have to cases 
        // we would go from left to right and find how many elements are not in right position 
        // and same with right to left
        // since we want this to be ascending sorted from left to right we will basically check for 
        // elements which are greater than the previous next element as this will contribute to sorting
        // similarly for right to left all the element must be in descending order so , 
        // if any current element is smallere than the previous that means it is not in correct order 
        // so we will mark the start and end index for this operation 
        // and finally we will return range which is end - start + 1 ( since it is 0 based index)
        
        int end = -1 ; 
        int mx_element_tillnow = nums[0];
        
        for( int i = 1 ; i < nums.size() ; i ++){
            if ( mx_element_tillnow > nums[i])
                // this means it is not in the correct order eg 10 9 -> it shoudl be 9 10
                end = i ;
            else 
                mx_element_tillnow = nums[i];
        }
        
        // we have traversed from left to right 
        
        int start = 0 ;
        int mn_element_tillnow = nums[nums.size() - 1];
        
        for( int i = nums.size()-2 ; i >= 0 ; i --){
            if ( mn_element_tillnow < nums.at(i))
                // this means they are not in correct position eg 10 9 -> it should be 9 10
                start = i;
            else 
                mn_element_tillnow = nums.at(i);
        }
        
        // finally returning the answer
        return end - start + 1;
    }
};