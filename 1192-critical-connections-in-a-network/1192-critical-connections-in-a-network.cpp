class Solution {
public:
    void dfs(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<vector<int>>& bridge,vector<vector<int>>& m)
    {        
        static int t=0;
        disc[u]=low[u]=t++;         
        for(int v:m[u])
        {
            if(disc[v]==-1)
            {
                parent[v]=u;
                dfs(v,disc,low,parent,bridge,m);
				
                low[u]=min(low[u],low[v]);
				
                if(low[v]>disc[u])                
                    bridge.push_back({u,v}); 
            }
            else if(v!=parent[u])
                    low[u]=min(low[u],disc[v]);            
        }       
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if(connections.size()==1) return connections;
		
        vector<vector<int>> m(n); //edges' list
        vector<int> disc(n,-1),low(n,-1),parent(n,-1);
        vector<vector<int>> bridge;
        
        for(int i=0;i<connections.size();i++)
        {
            int src=connections[i][0];
            int dest=connections[i][1];
            m[src].push_back(dest);
            m[dest].push_back(src);
        }
        for(int i=0;i<n;++i)
        {
            if(disc[i]==-1)               
                dfs(i,disc,low,parent,bridge,m);
         }                     
      return bridge;
    }    
};