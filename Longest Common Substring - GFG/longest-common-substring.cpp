//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    
    // int ans(string s1, string s2, int n, int m){
    //     if(n == -1 || m == -1) return 0;
    //     if(s1[n] == s2[m]){
    //         return 1 + ans(s1,s2,n-1,m-1,a);
    //     }else{
    //         a = max(a, max(ans(s1,s2,n-1,m,a), ans(s1,s2,n,m-1,a)));
    //         return a;
    //     }
    // }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        // vector<pair<int, int>> dp;
        for(int i = 0; i <= n ; i++) dp[i][0] = 0;
        for(int i = 0 ;i <= m ; i++) dp[0][i] = 0;
        
        // string str = "";
        int ans = 0;
        for(int i= 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ;j++){
                if(S1[i-1] == S2[j-1]){
                     dp[i][j] = 1 + dp[i-1][j-1];
                     ans = max(ans, dp[i][j]);
                    // str += text1[i-1];
                }
                else dp[i][j] = 0;
                
            }
        }
        //  cout << str;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends