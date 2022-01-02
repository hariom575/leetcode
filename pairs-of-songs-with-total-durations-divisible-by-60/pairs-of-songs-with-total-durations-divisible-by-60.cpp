class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
     map<int,int>m;
        int n=time.size();
        for(int i=0;i<n;i++){
            m[time[i]%60]++;
            time[i]%=60;
            cout<<time[i]<<" ";
        }
        int ans=0;
        int k=m[0];
        if(k>0)
        ans+=(k*(k-1));
        cout<<ans<<" ";
        for(int i=0;i<n;i++){
            int c=60-time[i];
            ans+=m[c];
            if(c==time[i])
                ans--;
        }
        return ans/2;
    }
};