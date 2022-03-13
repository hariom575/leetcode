class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                if(st.size()>0){
                    st.pop();
                }
            }
            else{
                st.push('[');
            }
        }
        return (st.size()+1)/2;
    }
};