class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
     map<int,int>tp;
     map<int,int>bt;
        map<int,int>common;
        int n=tops.size();
        for(auto a:tops) tp[a]++;
        for(auto a:bottoms) bt[a]++;
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                common[tops[i]]++;
            }
        }
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            int sum=tp[i]+bt[i]-common[i];
            cout<<common[i]<<" ";
            if(sum<n) continue;
            int ans1=n-tp[i];
            int ans2=n-bt[i];
            ans=min(ans,min(ans1,ans2));
        }
        return ans==INT_MAX?-1:ans;
    }
};