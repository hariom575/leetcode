class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 0, e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(isPossible(bloomDay, mid, m, k)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    
    bool isPossible(vector<int>& bDay, int mid, int m, int k){
        int adjacent = 0, count = 0;
        for(int i = 0; i < bDay.size(); i++){
            if(bDay[i] <= mid){
                adjacent++;
            }
            else{
                adjacent = 0;
            }
            if(adjacent==k){
                count++;
                adjacent = 0;
            }
        }
        if(count < m){
            return false;
        }
        else{
            return true;
        }
    }
};