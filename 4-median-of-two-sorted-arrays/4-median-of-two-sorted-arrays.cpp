class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int m1=n/2;
        int m2=n/2-1;
        int num1=0,num2=0;
        int i=0,j=0;
        while(i<n1 and j<n2){
            if(m1==0){
                num1=min(nums1[i],nums2[j]);
            }
             if(m2==0){
                num2=min(nums1[i],nums2[j]);
            }
            if(nums1[i]<nums2[j]){
                i++;
            }else j++;
            m1--;
            m2--;
        }
        while(i<n1){
            if(m1==0){
                num1=nums1[i];
            }
            if(m2==0){
                num2=nums1[i];
            }
            i++;
            m1--;
            m2--;
        }
         while(j<n2){
            if(m1==0){
                num1=nums2[j];
            }
            if(m2==0){
                num2=nums2[j];
            }
            j++;
            m1--;
            m2--;
        }
         if(n%2==0){
        double re = num1 + num2;
        return re/2;
    }
    double re = num1;
    return re; 
    }
};