class Solution {
public:
    bool isValid(string s) {
        // O(1) hash table
        unordered_map<char, char> matching_brackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        // O(n) vector
        stack<char> opening_brackets;
        
        for(auto &b: s){
            // if an opening bracket, push to the stack
            if(!matching_brackets.contains(b)) {
                cout << b;
                opening_brackets.push(b);
            } 
            // if a closing bracket, check if it closes its matching bracket
            else {
                if(opening_brackets.empty()) {
                    return false;
                }
                if(opening_brackets.top() != matching_brackets[b]) {
                    return false;
                } else {
                    opening_brackets.pop();
                }
            }
        }
    return opening_brackets.empty();
    }
};
