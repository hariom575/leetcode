class Solution {
public:
    vector<vector<string>>res;
    vector<string>te;
    unordered_map<string,int>mp;
    string b;
    void dfs(string s){
        te.push_back(s);
        if(s==b){
            vector<string>x=te;
            reverse(x.begin(),x.end());
            res.push_back(x);
            te.pop_back();
            return;
        }
        int cur=mp[s];
        for(int i=0;i<s.size();i++){
            char c=s[i];
            for(char ch='a';ch<='z';ch++){
                s[i]=ch;
                if(mp.count(s) and mp[s]==cur-1) {
                    dfs(s);
                }
            }
            s[i]=c;
        }
        te.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordlist) {
        unordered_set<string>dict(wordlist.begin(),wordlist.end());
        queue<string>q;
        int k= beginWord.size();
        q.push({beginWord});
        mp[beginWord]=0;
        b=beginWord;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string t=q.front();
                q.pop();
                int x=mp[t]+1;
                for(int i=0;i<k;i++){
                    string temp=t;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        if(!mp.count(temp) and dict.count(temp)){
                            mp[temp]=x;
                            q.push(temp);
                        }
                    }
                }
            }
        }
        if(mp.count(endWord))
            dfs(endWord);
        return res;
    }
};