class Solution {
public:
 double findMedianSortedArrays(vector<int>& s1, vector<int>& s2) {
        int n1 = s1.size(), n2=s2.size();
        if(n1>n2)
            return findMedianSortedArrays(s2, s1);
        
        if(n1==0)
            return double((s2[(n2-1)/2]+s2[n2/2]))/2;
            
        int tot_l = (n1+n2+1)/2;
        int L=0, R=n1; // for cut1 boundary in s1
        int cut1, cut2;
        double L1,L2,R1,R2;
        
        while(R>=L){
            cut1 = (R+L)/2;
            cut2 = tot_l - cut1;
            L1 = (cut1==0) ? -INFINITY:double(s1[cut1-1]); //4 boundary cases
            L2 = (cut2==0) ?  -INFINITY:double(s2[cut2-1]);
            R1 = (cut1==n1) ? INFINITY:double(s1[cut1]);
            R2 = (cut2==n2) ? INFINITY:double(s2[cut2]);
            
            if( L1 > R2) // move R to left 
                R = cut1;  
            else if(L2 > R1) // move L to right
                L = cut1+1;
            else{
                if((n1+n2)%2) // odd
                    return max(L1,L2);
                return (max(L1,L2)+min(R1, R2))/2;
            }
        }
        return -1;
    }
};