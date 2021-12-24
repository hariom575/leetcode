class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int end=1;
        int low,high;
        for (int i=1;i<n;i++){
            low=i-1,high=i;
            while (low>=0 && high<n && s[low]==s[high]){
                if (high-low+1>end){
                    start=low;
                    end=high-low+1;
                }
                low--;
                high++;
            }
            low=i-1,high=i+1;
            while (low>=0 && high<n && s[low]==s[high]){
                if (high-low+1>end){
                    start=low;
                    end=high-low+1;
                }
                low--;
                high++;
            }
        }
        return s.substr(start,end);
    }
};