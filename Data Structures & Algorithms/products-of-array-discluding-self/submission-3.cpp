class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // get the running product O(n)
        // for each num, divide the total product by num and append to list
        int prod = 1;
        int non_zero_prod = 1;
        int zeros = 0;
        for(auto n: nums) {
            if(n!=0) {
                non_zero_prod *= n;
            } else {

                zeros ++;
            }
            prod *= n;
        }
        vector<int> ans;
        for(auto n: nums) {
            if(n==0) {
                if(zeros > 1) {
                    ans.push_back(prod);
                } else {
                    ans.push_back(non_zero_prod);
                }
            } else {
                ans.push_back(prod/n);
            }
        }
        return ans;
    }
};
