class Solution {
public:
    int minCostToMoveChips(vector<int>& p) {
        int n=p.size();
        sort(p.begin(),p.end());
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                int diff=abs(p[i]-p[j]);
                if(diff%2) cnt++;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};