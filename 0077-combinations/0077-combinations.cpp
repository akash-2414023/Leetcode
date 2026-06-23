class Solution {
public:
    vector<vector<int>> res;
    void solve (int i , int n , int k , vector<int>& curr){
        if(curr.size() == k){
            res.push_back(curr);
            return;
        }
        if(i>n) return;
        curr.push_back(i);
        solve(i+1,n,k,curr);
        curr.pop_back();
        
        solve(i+1,n,k,curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        solve(1,n,k,curr);
        return res;
    }
};