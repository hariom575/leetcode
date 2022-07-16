class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int a=0;
        while(i<j){
            int cur=min(height[i],height[j])*(j-i);
            a=max(a,cur);
            height[i]>height[j]?j--:i++;
}
        return a;
    }
};