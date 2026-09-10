class Solution {
    bool isRotated(int a, int b) {
        if( a <= b) {
            return false;
        }
        return true;
    }
public:
    int findMin(vector<int> &nums) {
        bool rotated = isRotated(nums[0], nums[nums.size()-1]);
        if(!rotated) {
            return nums[0];
        }
        // check the middle element first
        // compare the middle element to the one to the left of it 
        // if it is smaller, move higher to curr - 1
        // else, move your lower to your curr + 1
        // 2 3 4 5 6 1 
        // 6 1 2 3 4 5
        int l1 = 0;
        int h1 = nums.size()-1;

        int mid1 = (l1 + h1)/2;


        while(l1 <= h1) {
            mid1 = (l1 + h1)/2;
            if(nums[mid1] < nums[h1]) {
                h1 = mid1;
            } else {
                l1 = mid1 + 1;
            }
        }
        int best1 = nums[mid1];
       
        return best1;
    }
};
