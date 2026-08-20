class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> temp;
        
        for(auto i: nums) {
            if(temp.contains(i)) {
                return true;
            } else {
                temp[i] = 1;
            }
        }
        return false;
    }
};