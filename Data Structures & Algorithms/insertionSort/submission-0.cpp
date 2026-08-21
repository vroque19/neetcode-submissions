// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> res;
        for(int i = 0; i < pairs.size(); i++) {
            Pair curr_pair = pairs[i];
            int j = i - 1;
            while(j >= 0 && pairs[j].key > curr_pair.key) {
                pairs[j+1] = pairs[j];
                j -= 1;
            }
            pairs[j+1] = curr_pair;
            res.push_back(pairs);
        }
        return res;
    }
};
