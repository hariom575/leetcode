class Solution {
public:
    int minPartitions(string n) {
     int ans=0;
        for(auto a:n){
            int k=a-'0';
            ans=max(ans,k);
        }
        return ans;
    }
};