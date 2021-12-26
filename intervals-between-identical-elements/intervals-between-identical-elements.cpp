class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int mx=*max_element(arr.begin(),arr.end());
        int n=arr.size();
        map<int,vector<long long int>>m;
        vector<long long>sum(mx+1,0ll);
        vector<long long>ans(n,0ll);
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
            sum[arr[i]]+=i;
        }
        for(auto &a:m){
           long long int val=a.first;
            vector<long long int>v=a.second;
           long long int sz=v.size();
           long long int prev=0ll;
           /// cout<<sum[val]<<" ";
            for(long long int i=0;i<sz;i++){
            long long int z=v[i];
             ans[z]+=abs(prev-v[i]*i);
             prev+=v[i];
             long long  int suffix=abs(sum[val]-prev);
             long long int k=sz-1ll-i;
             ans[z]+=abs(suffix-k*v[i]);
               // cout<<ans[z]<<" ";
            }
        }
        return ans;
    }
};