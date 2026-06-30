class Solution {
public:
    bool isPossible(vector<int>& weights, int mid, int days) {
        int dayCount = 1;
        int load = 0;
        for(int i = 0 ; i < weights.size() ; i++){
            if(load + weights[i] > mid){
                dayCount++;
                load = weights[i];
            }else{
                load += weights[i];
            }
            if(dayCount > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool isValid = isPossible(weights, mid, days);
            if (isValid) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};