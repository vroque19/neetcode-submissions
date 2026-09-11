class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans = {};
        if(numbers.size() == 2) {
            return {1, 2};
        }
        // go through the list
        // keep track of diffs in a map
        // target - curr: (curr, idx+1)
        unordered_map<int, tuple<int, int>> seen;
        for(int i = 0; i < numbers.size(); i++) {
            int curr = numbers[i];
            int diff = target - curr;
            if(seen.contains(curr)){
                cout << "Found the pair" << endl;
                ans.push_back(get<1>(seen[curr]));
                ans.push_back(i+1);
                break;
            }
            seen[diff] = make_tuple(curr, i+1);
        }
        return ans;
    }
};
