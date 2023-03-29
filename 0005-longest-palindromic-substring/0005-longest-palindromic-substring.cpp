class Solution {
public:
    string longestPalindrome(string s) {
        int ma = INT_MIN;
        string ans;
        int n = s.size();
        
        for(int i = 0; i < n ; i++){
            int low = i , high = i;
            while(low >=0 && high < n && s[low] == s[high]){
                int val= high - low +1;
                if(ma < val){
                    ma = val;
                    ans = s.substr(low, val);
                }
                low--;high++;
            }
            low = i , high = i+1;
            while(low >=0 && high < n && s[low] == s[high]){
                int val= high - low +1;
                if(ma < val){
                    ma = val;
                    ans = s.substr(low, val);
                }
                low--;high++;
            }
        }
        return ans;
    }
};