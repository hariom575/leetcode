class Solution {
public:
    map<int, map<int, bool>>dp;
    
    bool solve(string str1, string str2, int index1, int index2){
        
        if(index1 >= str1.length() && index2 >= str2.length()){
            return true;
        }
        
        if(index1>=str1.length()){
            if((str2.length() - index2)%2!=0)
                return false;
            while(index2 <= str2.length()-2){
                if(str2[index2+1] == '*')
                    index2+=2;
                else
                    return false;
            }
            return true;
        }
        
        if(index2>=str2.length()){
            return false;
        }
        
        if(dp[index1].find(index2)!=dp[index1].end())
            return dp[index1][index2];
        
        bool res = false;
        
        if(index2+1 < str2.length() && str2[index2+1] == '*'){
            if(str1[index1] == str2[index2] || str2[index2] == '.'){
                res = res || solve(str1, str2, index1+1, index2) || solve(str1, str2, index1, index2+2);
            }   
            else{
                res = res || solve(str1, str2, index1, index2+2);
            }
        }
        if(str1[index1] == str2[index2] || str2[index2] == '.') 
            res = res || solve(str1, str2, index1+1, index2+1);
        
        return dp[index1][index2] = res;
    }
    
    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};