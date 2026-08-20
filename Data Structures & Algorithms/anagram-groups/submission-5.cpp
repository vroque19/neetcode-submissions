class Solution {
    // return the ascii value of the word
    int get_val(string word) {
        int res = 0;
        for(auto &c: word) {
            res += int(c);
        }
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // anagrams have the same number of chars and the same "val"
        vector<vector<string>> res = {};
        // keep track of the anagrams index in the vector
        unordered_map<string, int> anagram_indices;
        int last_idx = 0;
        for(auto &word: strs) {
            std::string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());
            // cout << sorted_word;
            if(!anagram_indices.contains(sorted_word)) {
                anagram_indices[sorted_word] = last_idx;
                res.push_back({word});
                last_idx++;
                continue;
            }
            // if its a valid anagram add it to the vector at its index
            res[anagram_indices[sorted_word]].push_back(word);
        }
        return res;
    }
};
