class Solution {
public:
    bool isPossible(vector<int>& quantities, int mid, int n) {
        int storesNeeded = 0;
        int size = quantities.size();
        for (int i = 0; i < size; i++) {
            storesNeeded += (quantities[i] + mid - 1) / mid;

            if (storesNeeded > n)
                return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int size = quantities.size();
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool isValid = isPossible(quantities, mid, n);
            if (isValid) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};