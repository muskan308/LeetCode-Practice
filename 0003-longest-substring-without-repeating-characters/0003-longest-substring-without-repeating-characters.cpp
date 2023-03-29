class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.size()==0) return 0;
        unordered_set<char> chars;
        int ans = 0, ma = INT_MIN;
        int i = 0, j = 0;
        while(j < s.size()){
            if(!chars.count(s[j])){
                ans++;
                chars.insert(s[j]);
                j++;
            }else{
                ma = max(ma, ans);
                while(chars.count(s[j])){
                    chars.erase(s[i]);
                    i++;
                    ans--;
                    
                }
            }
        }
        ma = max(ma, ans);
        return ma ;
    }
};