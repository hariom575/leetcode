class Solution {
public:
    bool check(vector<int>&a,vector<int>&b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>v;
        vector<int>a(26,0);
        vector<int>b(26,0);
        int n=s.size();
        int k=p.size();
        for(int i=0;i<p.size();i++){
            a[p[i]-'a']++;
        }
        for(int i=0;i<min(k,n);i++){
            b[s[i]-'a']++;
        }
        int cnt=0;
        if(check(a,b)) v.push_back(0);
        for(int i=k;i<n;i++){
            b[s[i-k]-'a']--;
            b[s[i]-'a']++;
            if(check(a,b)) v.push_back(i-k+1);
        }
        return v;
    }
};