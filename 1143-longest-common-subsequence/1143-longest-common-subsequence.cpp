class Solution {
public:
    
//     int ans(string t1, string t2, int s1, int s2, vector<vector<int>> &dp){
//         if(s1 < 0 || s2 < 0 )return 0;
//         if(t1[s1] == t2[s2]) return dp[s1][s2] = 1 + ans(t1, t2, s1-1, s2-1, dp);
//         if(dp[s1][s2] != -1) return dp[s1][s2];
//         else return dp[s1][s2] =  max(ans(t1,t2,s1-1,s2, dp), ans(t1,t2,s1,s2-1, dp));
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        
        for(int i = 0; i <= n ; i++) dp[i][0] = 0;
        for(int i = 0 ;i <= m ; i++) dp[0][i] = 0;
        
        for(int i= 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ;j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                
            }
        }
         
        return dp[n][m];
    }
};