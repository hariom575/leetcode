class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int cur=0;
        int tot=0;
        int n=gas.length;
        int start=0;
        for(int i=0;i<n;i++){
            tot+=gas[i]-cost[i];
            cur+=gas[i]-cost[i];
            if(cur<0){
                cur=0;
                start=i+1;
            }
        }
        if(tot>=0) return start;
        return -1;
    }
}