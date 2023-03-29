class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.size()==0) return 0;
        // unordered_set<char> chars;
        int ans = 0, ma = INT_MIN;
        int i = 0, j =0;
        vector<int> index(256, -1); 
        while(j < s.size()){
            if(index[s[j]] == -1){
                ans++;
                index[s[j]] = 1;
                j++;
            }else{
                ma = max(ma, ans);
              //  cout << ma << endl;
                while(index[s[j]] == 1){
                    index[s[i]] = -1;
                    i++;
                    ans--;
                    
                }
            }
        }
        ma = max(ma, ans);
        return ma ;
    }
};