class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones = 0;
        int zeros = 0;
        for(auto s: students) {
            ones += s;
            zeros += !s;
        }
        int p = 0;
        while(p < sandwiches.size()) {
            if(1 == sandwiches[p] && ones > 0) {
                ones -= 1;
                p++;
            }
            else if(0 == sandwiches[p] && zeros > 0) {
                zeros -= 1;
                p++;
            }
            else {
                break;
            }
            
        }
        return ones + zeros;
    }
};