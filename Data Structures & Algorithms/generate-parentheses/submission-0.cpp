class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(n, 0, 0, "", res);
        return res;
    }

private:
    void backtrack(int n, int open_count, int closed_count, string curr, vector<string>& res) {
        if(open_count == closed_count && open_count == n) {
            res.push_back(curr);
            return;
        }
        if(open_count < n) {
            backtrack(n, open_count + 1, closed_count, curr + "(", res);
        }
        if(closed_count < open_count) {
            backtrack(n, open_count, closed_count + 1, curr + ")", res);
        }
    }

};
