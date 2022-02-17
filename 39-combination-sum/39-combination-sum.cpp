class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, vector<int>a,int target,int start){
      int n=candidates.size();
        if(target==0){
            cout<<a.size();
          ans.push_back(a);
            return;
        }
        if(target<0)
            return;
        for(int i=start;i<n;i++){
            a.push_back(candidates[i]);
            helper(candidates,a,target-candidates[i],i);
             a.pop_back();
}
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>a;
            ans.clear();
        helper(candidates, a, target,0);
        return ans;
    }
};