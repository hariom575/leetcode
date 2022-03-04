class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
  vector<vector<double>> store(query_row + 1, vector<double>(query_row + 1, 0));
  store[0][0] = poured;
  for (int i = 1; i <= query_row; ++ i) {
	for (int j = 0; j <= i; ++ j) {
	  if (j == 0) {
		store[i][j] = max(0.0, (store[i - 1][j] - 1) / 2.0);
	  } else {
		store[i][j] = max(0.0, (store[i - 1][j] - 1) / 2.0) + max(0.0, (store[i - 1][j - 1] - 1) / 2.0);
	  }
	}
  }
  return min(1.0, store[query_row][query_glass]);
}
};