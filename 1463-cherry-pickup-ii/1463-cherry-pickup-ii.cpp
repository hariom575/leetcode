class Solution {
    static int step(vector<vector<int>>& grid, int lvl, int left, int right, unordered_map<int, int> memo[])
    {
        if(lvl >= grid.size() || left < 0 || left >= grid[0].size() || right < 0 || right >= grid[0].size())
            return 0;
        
        int hash = min(left, right)*70 + max(left, right);
        if(auto f = memo[lvl].find(hash); f != memo[lvl].end())
            return f->second;
        
        int sum = grid[lvl][left] + (left == right ? 0 :  grid[lvl][right]);

        return memo[lvl][hash] = sum +
            max( {
                step(grid, lvl+1, left - 1, right - 1, memo),
                step(grid, lvl+1, left, right - 1, memo),
                step(grid, lvl+1, left + 1, right - 1, memo),
                step(grid, lvl+1, left - 1, right, memo),
                step(grid, lvl+1, left, right, memo),
                step(grid, lvl+1, left + 1, right, memo),
                step(grid, lvl+1, left - 1, right + 1, memo),
                step(grid, lvl+1, left, right + 1, memo),
                step(grid, lvl+1, left + 1, right + 1, memo)
            } );
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        unordered_map<int, int> memo[grid.size()];
        return step(grid, 0, 0, grid[0].size() - 1, memo);
    }
};