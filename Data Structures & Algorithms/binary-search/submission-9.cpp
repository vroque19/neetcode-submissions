class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        int min = 0;
        int max = nums.size() - 1;
        if(nums[0] == target) {
            return 0;
        }
        if(nums[max] == target) {
            return max;
        }
        while(min <= max) {
            int curr = min + (max - min) / 2;
            if(nums[curr] < target) {
                min = curr + 1;
            }
            else if( nums[curr] > target) {
                max = curr - 1;
            }
            else {
                res = curr;
                return res;
            }
        }
        return res;
    }
};