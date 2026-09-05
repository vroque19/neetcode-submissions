class Solution {

    int simulate(vector<int>& arr, int k) {
        int time = 0;
        for(auto pile: arr) {
            time += (pile/k) + (pile%k!=0);
        }
        cout << "time" << time << endl;
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       // i piles
       // h hours
       // return k bananas per hour you can eat
       // cannot eat from more than 1 pile per hour
       // you must eat all the bananas in h hours
       // 1 <= l <= largest pile
        sort(piles.begin(), piles.end());
        int p = piles.size()-1;
        int k = piles[p];
        if(h == 1) {
            return k;
        }
        if(h == piles.size()) {
            return k;
        }
        int best = k;
        int mink = 1;
        int maxk = k;
        while(mink<=maxk) {
            cout << mink << maxk << endl;
            k = (mink+maxk)/2;
            int curr_time = simulate(piles, k);
            if(curr_time <= h) {
                best = k;
                maxk = k - 1;
            }
            else {
                mink = k + 1;
            }
            
        }
        return best;

        

    }
};
