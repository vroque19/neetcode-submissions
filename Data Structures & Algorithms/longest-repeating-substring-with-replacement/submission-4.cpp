class Solution {
public:
    int characterReplacement(string s, int k) {
        // maximize the longest substring
        /*
        curr max: 4 
        AAABCAAAAAA max: 
            p     p 
        - check the first two chars
        - valid chars are either of the first 2 chars
        a window is valid when all the characters are eqaul expect for k of them
        */
        if(s.size() < 2) {
            return 1;
        }
        int p1 = 0;
        int p2 = 0;
        int best = 0;
        int max_freq = 0;
        vector<int> count(26, 0);
        while(p2 < s.size()) {
            count[s[p2] - 'A']++;
            max_freq = max(max_freq, count[s[p2] - 'A']);
            int len = p2 - p1 + 1;
            while(len - max_freq > k) {
                count[s[p1] - 'A']--;
                p1++;
                len = p2 - p1 + 1;
            }
            best = max(best, len);
            p2++;
        }
        return best;

    }
};