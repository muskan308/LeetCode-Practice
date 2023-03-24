//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        // code here
        if(s.size() == 0) return s;
        int n = s.size();
        string ans = "";
        
        for(int i = 0; i < n; i++){
            bool flag = false;
            while(i != n-1 && s[i] == s[i+1]) {
                flag = true;
                i++;
            }
            if(!flag)ans += s[i];
        }
        if(s == ans) return ans;
        return rremove(ans);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends