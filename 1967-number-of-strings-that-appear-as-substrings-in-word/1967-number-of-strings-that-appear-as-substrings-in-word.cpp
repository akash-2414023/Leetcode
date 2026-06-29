class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(string x : patterns){
            if(word.contains(x)){
                cnt++;
            }
        }
        return cnt;
    }
};