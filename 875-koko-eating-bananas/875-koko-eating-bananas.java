class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left=1;
        int right=(int)1e9;
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(canEat(piles,mid,h)){
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return ans;
    }
    boolean canEat(int[] piles,int k,int hours){
        int h=0;
        for(int pile:piles){
            int a=(pile/k);
            if(pile%k>0) a++;
            h+=a;
        }
        return h<=hours;
    }
}