class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int n=matrix.size();
      int m=matrix[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            cout<<mid<<" ";
            if(matrix[mid][0]>target) high=mid-1;
            else if(matrix[mid][m-1]<target) low=mid+1;
            else{
                int l=0;
                int h=m-1;
                while(l<=h){
                    int m=(l+h)/2;
                    if(matrix[mid][m]==target) return true;
                    else if(matrix[mid][m]>target) h=m-1;
                    else l=m+1;
                }
                return false;
            }
        }
        return false;
    }
};