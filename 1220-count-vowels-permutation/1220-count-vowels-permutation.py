class Solution:
    def countVowelPermutation(self, n: int) -> int:
        M = 10**9+7
        N = 5
        dp = [1]*N
        G = {'a':['e','i','u'],'e':['a','i'],'i':['e','o'],'o':['i'],'u':['i','o']}
        d = {'a':0,'e':1,'i':2,'o':3,'u':4}
        for i in range(1,n):
            new_dp = [0]*N
            for v in G:
                for w in G[v]:
                    new_dp[d[v]] = (new_dp[d[v]]+dp[d[w]])%M
            dp = new_dp
        return sum(dp)%M
        