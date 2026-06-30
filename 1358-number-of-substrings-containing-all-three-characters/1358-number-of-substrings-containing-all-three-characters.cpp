class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> freq(3, 0);
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < n) {
            freq[s[right] - 'a']++;
            while (freq[0] && freq[1] && freq[2]) {
                ans += (n - right);
                freq[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        return ans;
        /*int n = s.size();
        int cnt = 0;
        vector<int>lastSeen(3,-1);
        for(int i = 0 ; i < n ; i++){
            lastSeen[s[i]-'a'] = i;
            if(lastSeen[0]!= -1 && lastSeen[1]!= -1 && lastSeen[2]!= -1 ){
                cnt+=(1+min({lastSeen[0],lastSeen[1],lastSeen[2]}));
            }
        }
        return cnt;*/
    }
};