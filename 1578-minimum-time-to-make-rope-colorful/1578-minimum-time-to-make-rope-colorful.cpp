class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int n=colors.size();
        for(int i=0;i<n;i++){
            int j=i;
            int cursum=neededTime[i];
            int mx=neededTime[i];
           /// cout<<colors[i];
           // if(j+1<n) cout<<colors[j+1]<<" ";
            while(j+1<n and colors[j+1]==colors[i]) {
                ///cout<<j+1<<endl;
            mx=max(neededTime[j+1],mx);
            cursum+=neededTime[j+1];
            j++;
            }
            i=j;
           // cout<<cursum-mx<<" ";
           // cout<<cursum<<" ";
            ans+=cursum-mx;
           // co
        }
        return ans;
    }
};