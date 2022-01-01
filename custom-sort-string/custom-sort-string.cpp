class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        map<char,int> mp1;
        
        for(char ch: order) mp[ch]++;
        for(char ch: s) mp1[ch]++;
        string ans;
        
        for(char ch: order){
            auto it = mp1.find(ch);
            if(it!=mp1.end()) {
                int x = it->second;
                while(x--) ans+=ch;
            }
        }
        
        for(char ch: s){
            auto it = mp.find(ch);
            if(it==mp.end()) ans+=ch;
        }
        
        return ans;
        
    }
};