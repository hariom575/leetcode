class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        map<char,char>mp;
        mp[')']='(';
        mp[']']='[';
        mp['}']='{';
        for(auto a:s){
            if(a=='(' || a=='{' || a=='['){
                st.push(a);
            }else{
                cout<<a;
                ///cout<<st.top();
             if(st.empty() || st.top()!=mp[a]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};