class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>st;
        vector<string>v={
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        for(auto a:words){
            string ans="";
            for(auto b:a){
                int idx=b-'a';
                ans+=v[idx];
            }
            st.insert(ans);
        }
        return st.size();
    }
};