class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>mat(n+1,vector<int>(n+1,0));
        for(auto &a:trust){
            mat[a[0]][a[1]]=1;
        }
        stack<int>s;
        for(int i=1;i<=n;i++){
            s.push(i);
        }
       while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(mat[a][b]){
                s.push(b);
            }
            else if(mat[b][a]){
                s.push(a);
            }
        }
        int ans=-1;
        if(s.size()>=1)
            ans=s.top();
        if(ans==-1) return ans;
        for(int i=1;i<=n;i++){
            if(mat[ans][i]) return -1;
        }
        return ans;
    }
};