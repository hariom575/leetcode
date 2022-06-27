class Solution {
public:
   int kadane(vector<int>& n1, vector<int>& n2) {
    int sz = n1.size(), sum = 0, res = 0;
    for (int i = 0; i < sz; ++i) {
        sum = max(n2[i] - n1[i], sum + n2[i] - n1[i]);
        res = max(res, sum);
    }
    return res;
}
int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
    return max(accumulate(begin(n1), end(n1), 0) + kadane(n1, n2),
               accumulate(begin(n2), end(n2), 0) + kadane(n2, n1));
}
};