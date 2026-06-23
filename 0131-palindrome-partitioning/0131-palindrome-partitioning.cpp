class Solution {
public:
    vector<vector<string>> res;
    int n;
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(int idx, string& s, vector<string>& curr) {
        if (idx == n) {
            res.push_back(curr);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> curr;
        solve(0, s, curr);
        return res;
    }
};