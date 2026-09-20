class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int res = 0;
        while (l <= r) {
            int width = r - l;
            int area = min(heights[l], heights[r]) * width;
            res = max(res, area);
            if(heights[l]<= heights[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return res;
    }
};
