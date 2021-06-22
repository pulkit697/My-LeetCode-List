// https://leetcode.com/problems/container-with-most-water/
// Time O(N)
// Space O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,area=0;
        while(l<r){
           area=max(area,(min(height[l],height[r])*abs(r-l)));
           if(height[l]<height[r]){
               l++;
           } else{
               r--;
           } 
        }
        return area;
    }
};