class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // get the running prefix product and store prefix_prod[i]
        // get the running suffix product and store suffix_prod[i]
        // [-1,0,1,2,3]
        vector<int> pre(nums.size()); // nothing to the left of the first element
        vector<int> suf(nums.size());
        vector<int> ans;
        pre[0] = 1;
        suf[nums.size()-1] = 1;
        for(int l = 1; l < nums.size(); l++) {
            int r = nums.size() - 1-l;
            pre[l] = nums[l-1] * pre[l-1];
            suf[r] = nums[r+1] * suf[r+1];
            r--;
        }
        for(int i{}; i < nums.size(); i++) {
            ans.push_back(pre[i]*suf[i]);
        }
        return ans;
    }
};
