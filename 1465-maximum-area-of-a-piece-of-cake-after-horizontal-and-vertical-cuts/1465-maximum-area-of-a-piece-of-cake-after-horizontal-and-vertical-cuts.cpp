#define ll long long 
class Solution {
public:
    ll mod=1e9+7;
    
    int maxArea(int x, int y, vector<int>& h, vector<int>& v) {
        h.push_back(0);
        h.push_back(x);
        v.push_back(0);
        v.push_back(y);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        ll a=0;
        ll b=0;
        for(int i=1;i<h.size();i++){
            ll diff=h[i]-h[i-1];
           // cout<<diff<<" ";
            a=max(a,diff);
            a%=mod;
        }
        for(int i=1;i<v.size();i++){
           ll diff=v[i]-v[i-1];
            //cout<<v[i]<<" ";
            b=max(b,diff);
            b%=mod;
        }
        return (a%mod*b%mod)%mod;
    }
};