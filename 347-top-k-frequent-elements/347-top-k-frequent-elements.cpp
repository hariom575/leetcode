class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto a:nums) mp[a]++;
        vector<pair<int,int>>v;
        for(auto a:mp){
            v.push_back({a.second,a.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<int>ans;
        for(auto a:v){
            if(k<=0) break;
            ans.push_back(a.second);
            k--;
        }
        return ans;
    }
};