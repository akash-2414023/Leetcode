class Solution {
public:
    long long func(vector<int>& piles, int hourly) {
        long long totalHrs = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            totalHrs += ((piles[i] + hourly - 1)/hourly);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int maxval = *max_element(piles.begin(), piles.end());
        int high = maxval;
        int ans = maxval;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalHr = func(piles, mid);
            if (totalHr <= h) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};