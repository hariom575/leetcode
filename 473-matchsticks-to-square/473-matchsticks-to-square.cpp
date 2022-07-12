class Solution {
public:
    bool recur(vector<int>& match,int s1,int s2,int s3,int s4,int i,int n,map<vector<int>,bool> &m,int tar)
    {
        if(i == n)
        {
          return (s1 == s2 && s2 == s3 && s3 == s4);   
        }
 if(s1 >tar || s2 >tar || s3 >tar || s4 >tar) // important condition for returning if any sum is greater than target 
            return false;
        vector<int> v = {s1,s2,s3,s4};
        sort(v.begin(),v.end());//Sort for Memoization
        if(m.find(v) != m.end())
            return m[v];
bool t = recur(match,s1+match[i],s2,s3,s4,i+1,n,m,tar)|| recur(match,s1,s2+match[i],s3,s4,i+1,n,m,tar)|| recur(match,s1,s2,s3+match[i],s4,i+1,n,m,tar)|| recur(match,s1,s2,s3,s4+match[i],i+1,n,m,tar);
        return m[v] = t;
    }
    bool makesquare(vector<int>& match) {
        int s = 0;
        int n = match.size();
        for(auto i:match)
            s+=i;
        if(s%4 != 0)
            return false;
        int tar = s /4;
        map<vector<int>,bool> dp;
        sort(match.begin(), match.end(), [](const int &l, const int &r){return l > r;});
        return recur(match,0,0,0,0,0,n,dp,tar);
        
        
    }
};