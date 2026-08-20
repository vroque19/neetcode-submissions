class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f_map;
        for(auto n: nums) {
            f_map[n]++;
        }
        using Element = pair<int, int>;
        // use a min heap to get top K elements sorted by {frequency: element}
        priority_queue<Element, vector<Element>, greater<Element>> min_heap; 

        // go through the f_map and push to the freq map
        for(auto &[key, v]: f_map) {
            min_heap.push({v, key});
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> top_k;
        while(!min_heap.empty()) {
            top_k.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return top_k;
    }
};
