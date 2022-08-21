class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
    long long sum = 0;
	// out stores the sum which needs to be subtracted from the maximum sum
    vector<long long> ans, out;
    for(int num: nums) {
        if(num > 0)
            sum += num;
    }
    for(int& num: nums) {
        num = abs(num);
    }
    sort(nums.begin(), nums.end());
    priority_queue<array<long long, 2>, vector<array<long long, 2>>, greater<array<long long, 2>>> pq;
    int n = nums.size();
    pq.push({nums[0], 0});
    while(pq.size() && out.size() < k - 1) {
        auto t = pq.top();
        long long o = t[0], i = t[1];
        pq.pop();
        out.push_back(o);
        if(i + 1 < n) {
            pq.push({o+nums[i+1],i+1});
            pq.push({(o-nums[i])+nums[i+1],i+1});
        }
    }

    ans.push_back(sum);
    for(long long o: out) {
        ans.push_back(sum - o);
    }
    //return Kth largest sum 
    return ans[k-1];
    }
};