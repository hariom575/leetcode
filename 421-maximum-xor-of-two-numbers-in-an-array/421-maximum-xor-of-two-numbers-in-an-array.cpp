  class TrieNode{
      public :
          TrieNode * child[2];
        TrieNode(){
            this->child[0]=NULL;
            this->child[1]=NULL;
        }
    };
class Solution {
public:
      TrieNode *newnode;
    void insert(int x){
        TrieNode *t =newnode;
        bitset<32>bs(x);
        for(int j=31;j>=0;j--){
            if(!t->child[bs[j]]) t->child[bs[j]]=new TrieNode();
            t=t->child[bs[j]];
        }
    }
    int maxXOr(int x){
        TrieNode *t=newnode;
        int ans=0;
        bitset<32>bs(x);
        for(int i=31;i>=0;i--){
            if(t->child[!bs[i]]) ans+=(1<<i) ,t=t->child[!bs[i]];
            else t=t->child[bs[i]];
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        newnode =new TrieNode();
        for(auto &n :nums)
            insert(n);
        int ans=0;
        for(int n:nums){
               ans=max(ans,maxXOr(n));
        }
        return ans;
    }
};