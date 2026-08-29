class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2){
            return nums.size();
        }
        sort(nums.begin(), nums.end());
        int res = 1;
        int best = res;
        for(int i = 1; i < nums.size(); i++) {
            cout << nums[i];
            int diff = nums[i] - nums[i-1];
            if(diff == 0) {
                continue;
            }
            // -3-2-1 1 ; 2 3 4 6 ; 7 8 9
            else if(diff > 1) {
                cout << diff << " is greater than 1\n";
                if(res >= best) {
                    best = res;
                    res = 1;
                }
                continue;
            }
            res ++;
        }
        if(res > best) {
            best = res;
        }
        return best;
    }
};
