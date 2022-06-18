class Solution {
public:
    string longestPalindrome(string s) {
 string r = s;
    int n=s.length();
 //   s = s + "$" + r;
        int start=0;
        int maxlen=0;
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g==0){
                    dp[i][j]=true;
                    start=i;
                    maxlen=j-i+1;
                }
                else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                      start=i;
                    maxlen=j-i+1;
                    }
                }
                else{
                   // cout<<i<<j;
                 if(s[i]==s[j] and dp[i+1][j-1]){
                        dp[i][j]=true;
                     if(j-i+1>maxlen){
                          start=i;
                    maxlen=j-i+1;
                     }
                 }
                }
}
}
       // cout<<dp[2][3];
      //  cout<<start;
        return s.substr(start,maxlen);
    }
};