class Solution {
public:
    int longestValidParentheses(string s) { int n=s.length();
        stack<int> pp;
        pp.push(-1);
        int result=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                pp.push(i);  //index where problem occor we may not find closing bracket fot this bracket
            }
            else
            {
                pp.pop();
                if(!pp.empty())
                {
                    result = max(result,i-pp.top());
                }
                else
                {
                    pp.push(i);  //index where problem occurs 
                }
                
            }
            
        }
        
        return result;
        
    }
};