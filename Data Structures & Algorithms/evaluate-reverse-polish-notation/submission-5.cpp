class Solution {
    string evaluate(string t1, string t2, string op) {
        int res = 0;
        int n1 = stoi(t1);
        int n2 = stoi(t2);
        if(op == "+") {
            res = n1+n2;
        }
        else if(op == "-") {
            res = n1 - n2;
        }
        else if(op == "*") {
            res = n1 * n2;
        }
        else {
            res = floor(n1/n2);
        }
        string ans = to_string(res);
        return ans;
    }
public:
    int evalRPN(vector<string>& tokens) {
        // for each token, append to a stack
        // at each operator, pop off the stack
        // and compute the operation with those two 
        // integers
        // push the result back on the stack
        stack<string> rpn;
        set<string> ops = {"*", "-", "+", "/"};
        for(auto &t: tokens) {
            if(ops.find(t) != ops.end()) {
                string temp1 = rpn.top();
                rpn.pop();
                string temp2 = rpn.top();
                rpn.pop();

                string res = evaluate(temp2, temp1, t);
                rpn.push(res);
            }
            else {
                rpn.push(t);
            }
        }
        return stoi(rpn.top());
    }
};
