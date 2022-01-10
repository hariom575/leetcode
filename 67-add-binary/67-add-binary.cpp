class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,j=0;
        while(i<a.length() and j<b.length()){
            int k=a[i]-'0'+b[j]-'0'+carry;
          //  cout<<k<<" ";
            carry=k/2;
            k%=2;
            ans+=to_string(k);
            i++;
            j++;
        }
                while(i<a.length()){
            int k=a[i]-'0'+carry;
            carry=k/2;
            k%=2;
            ans+=to_string(k);
                    i++;
        }
            while(j<b.length()){
            int k=b[j]-'0'+carry;
            carry=k/2;
            k%=2;
            ans+=to_string(k);
                j++;
        }
        if(carry){
            ans+=to_string(carry);
        }
       // cout<<ans<<" ";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};