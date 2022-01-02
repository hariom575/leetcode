class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int high=arr.size()-1;
        int low=0;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]==target){
                return mid;
}else if(arr[mid]<target)
                low=mid+1;
            else
                high=mid-1;
            
}
        return low;
    }
};