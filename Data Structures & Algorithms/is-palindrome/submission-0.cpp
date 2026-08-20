class Solution {

bool isAlpha(char c) {
    if(c >= 'a' && c <= 'z') {
        return true;
    }
    if(c >= 'A' && c <= 'Z') {
        return true;
    }
    if(c >= '0' && c <= '9') {
        return true;
    }
    return false;
}
public:
    bool isPalindrome(string s) {
        int p1 = 0;
        string new_string = "";
        for(auto &c: s) {
          if(isAlpha(c)) {
            
            new_string += ((tolower(c)));
          }
        }
        int p2 = new_string.size() - 1;
        while(p2 > p1) {
            if(new_string[p1] == new_string[p2]) {
                p1+=1;
                p2-=1;
            } else {
                cout << new_string[p2] << new_string[p1];
                return false;
            }
        }
        return true;
    }
};
