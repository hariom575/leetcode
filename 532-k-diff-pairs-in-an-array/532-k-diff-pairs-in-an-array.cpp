class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      //  if(k==0) return 1;
      map<int,int>m;
        for(auto a:nums) m[a]++;
        int ans=0;
        map<int,int>mp;
        for(auto a:nums){
            if(mp.count(a)) continue;
            int b=a-k;
            if(b==a){
                if(m[a]>1) ans++;
}
           else if(m.count(a-k))
            ans+=(1);
            mp[a]++;
        }
        return ans;
    }
};