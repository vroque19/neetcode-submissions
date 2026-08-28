class Solution {
    vector<int> wrd_lengths;
public:

    string encode(vector<string>& strs) {
        // traverse the vector, appending each string to the mega
        // for every word, add that words length to the wrd_lengths array
        string res = "";
        for(auto wrd: strs) {
            res += wrd;
            wrd_lengths.push_back(wrd.size());
        }
        cout << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int curr = 0;
        for(int i = 0; i<wrd_lengths.size(); i++) {
            string subs = "";
            int end_length = curr + wrd_lengths[i];
            while(curr < end_length) {
                subs += s[curr];
                curr++;
            }
            res.push_back(subs);
          
        }
        return res;
    }
};
