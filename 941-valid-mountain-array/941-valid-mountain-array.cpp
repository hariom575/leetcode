class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       int i=0;
        int n=arr.size();
        while(i<n-1 and arr[i]<arr[i+1])
            i++;
        int j=n-1;
        while(j>0 and arr[j-1]>arr[j]) j--;
        if(j<=0 || i>=n-1) return false;
        return j<=i;
    }
};