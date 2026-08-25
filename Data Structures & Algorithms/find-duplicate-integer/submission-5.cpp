class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // the value of each item in the list points to another item at the index value
        // ex: [1, 2, 3, 4, 3]
        /*
        nums[0] -> num[1] ->num[2] ->num[3] ->num[4] ->num[3] cycle detected!
        */
        int p1 = nums[0];
        int p2 = nums[p1]; // always 1 ahead
        while(p1 != p2) {
            p1 = nums[p1];
            p2 = nums[nums[p2]]; // increment by 2
        }
        // found the cycle
        // must find the beginning of the cycle
        p2 = 0;
        while(p1 != p2) {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        // the pointers have intersected
        return p1;
    }
};