class Solution {
public:
    int mod=1e9+7;
    int countPairs(vector<int>& deliciousness) {
        vector<int>powers;
        int p=1;
        long long num=1;
        while(p<=31){
            powers.push_back(num);
            num*=2ll;
            p++;
        }
        long long ans=0;
        map<long long,long long>mp;
        for(auto a:deliciousness){
            mp[a]++;
        }
        for(auto b:powers){
            map<int,int>vis;
        for(auto [num,freq]:mp){
            if(vis[num]) continue;
                if(b<num) continue;
                int left=b-num;
                if(!mp.count(left)) continue;
                int freqleft=mp[left];
            vis[num]=1;
            vis[left]=1;
                if(left==num){
                    long long cnt=(freq*(freq-1))/2;
                    ans=(ans%mod+cnt%mod)%mod;
                    continue;
                }
                long long cur=(freq%mod*freqleft%mod)%mod;
                ans=(ans%mod+cur%mod)%mod;
            }
        }
        return ans;
    }
};