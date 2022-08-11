class Solution {
public:
    int dp[101][101];
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; ++i) {
            res = min(res, solve(matrix, i, 0, n));
        }
        return res;
    }
    int solve(vector<vector<int>> &v, int i, int j, int n) {
        if(j == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0) {
            
            return dp[i][j]  = v[j][i] + min(solve(v, i, j + 1, n), solve(v, i + 1, j + 1, n));
        }
        else if(i == n - 1) {
            return dp[i][j]  = v[j][i] + min(solve(v, i, j + 1, n), solve(v, i - 1, j + 1, n));
        }
        return dp[i][j]  = v[j][i] + min({solve(v, i, j + 1, n), solve(v, i - 1, j + 1, n), solve(v, i + 1, j + 1, n)});
    }
};