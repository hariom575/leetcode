class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        vector<int>a=nums;
        sort(a.begin(),a.end());
        int start=0;
        int end=n-1;
        while(start<n and a[start]==nums[start]) start++;
        while(end>=0 and  a[end]==nums[end]) end--;
        cout<<start<<" "<<end<<" ";
        if(start>=end) return 0;
        return end-start+1;
    }
};