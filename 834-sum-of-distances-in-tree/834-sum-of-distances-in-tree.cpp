class Solution {
public:
    int subsize[100004];
    int subdist[100004];
    int res[100004];
    void dfs(int node,int par,vector<vector<int>>&graph){
      subsize[node]=1;
        for(auto &a:graph[node]){
            if(a!=par){
               dfs(a,node,graph);
                subsize[node]+=subsize[a];
                subdist[node]+=subsize[a]+subdist[a];
            }
        }
    }
        void dfs1(int node,int par,int n,vector<vector<int>>&graph){
      res[node]=res[par]-subsize[node]-subdist[node]+n-subsize[node]+subdist[node];
        for(auto a:graph[node]){
           if(a!=par){
               dfs1(a,node,n,graph);
           }
       }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++){
            res[i]=0;
            subsize[i]=0;
            subdist[i]=0;
        }
        //size=vector<int>(n,0);
         vector<vector<int>>graph(n);
        for(auto a:edges){
           graph[a[0]].push_back(a[1]);
              graph[a[1]].push_back(a[0]);
        }
        dfs(0,-1,graph);
        res[0]=subdist[0];
       for(auto child:graph[0])
        dfs1(child,0,n,graph);
        vector<int>ans;
        for(int i=0;i<n;i++)
            ans.push_back(res[i]);
        return ans;
    }
};