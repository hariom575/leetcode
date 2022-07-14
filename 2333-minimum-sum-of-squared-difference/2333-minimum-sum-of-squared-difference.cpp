class Solution {
public:
  long long minSumSquareDiff(vector<int>& n1, vector<int>& n2, int k1, int k2) {
    for (int i = 0; i < n1.size(); ++i) 
        n1[i] = abs(n1[i] - n2[i]);
    long long l = 0, r = 100000, extra_ops = 0, res = 0;
    while (l < r) {
        long long m = (l + r) / 2, ops = 0;
        for (auto n : n1)
            ops += max(0LL, n - m);
        if (ops > k1 + k2)
            l = m + 1;
        else {
            r = m;
            extra_ops = k1 + k2 - ops;
        }
    }
    for (int n : n1) {
        long long val = n < l ? n : max(0LL, l - (--extra_ops >= 0 ? 1 : 0));
        res += val * val;
    }
    return res;
}
};