class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
        k = 3
        1 2 3 1 2 1
        l   r
        */
        unordered_map<int, int> map;
        int left = 0;
        int right = left;
        while(right < nums.size()) {
            map[nums[right]]++;
        
            if(map[nums[right]] > 1) {
                return true;
            }
            if(abs(right-left)+1 > k) {
                cout << left << right;
                map[nums[left]]--;
                left++;
            }
            right++;
        }
        return false;
    }
};