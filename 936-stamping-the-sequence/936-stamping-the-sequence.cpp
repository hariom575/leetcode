class Solution {
public:
    int star;
    bool check(string &stamp,string &target,vector<int>&ans,int start){
        for(int i=0;i<stamp.size();i++){
            if(target[i+start]!='*' && target[i+start] != stamp[i]) return false;
        }
        
        ans.push_back(start);
        
        for(int i=start;i-start<stamp.size();i++){
            if(target[i] != '*') star++;
            target[i]='*';
        }
        return true;
    }
    vector<int> movesToStamp(string stamp, string target) {
        vector<bool>vis(target.size(),false);
        vector<int>ans;
        star=0;
        if(stamp==target) return {0};
        while(star<target.size()){
            bool replaced=false;
            for(int i=0;i <= target.size()-stamp.size() and star<target.size();i++)
            {   
                if(!vis[i]){
                    replaced=check(stamp,target,ans,i);
                    vis[i]=replaced;
                }
            }
            if(!replaced) return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};