class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        set<int> BFS;
        set<int> visited; // visited indices
        BFS.insert(BFS.begin(),start);
        while(!BFS.empty())
        {
            int l=BFS.size();
            for(int i=0;i<l;++i)
            {
                auto it=BFS.begin();
                if(arr[*it]==0) return 1;
                visited.insert(visited.begin(),*it);
                int left=*it-arr[*it];
                int right=*it+arr[*it];
                if(left>=0&&visited.find(left)==visited.end())
                {
                    BFS.insert(BFS.end(),left);
                }
                if(right<n&&visited.find(right)==visited.end())
                {
                    BFS.insert(BFS.end(),right);
                }
                BFS.erase(it);
            }
        }
        return 0;
        
    }
};