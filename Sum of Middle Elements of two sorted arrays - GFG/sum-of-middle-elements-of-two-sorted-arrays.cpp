//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            if(n==1){
                return ar1[0]+ar2[0];
            }
            if(n == 2){
                return max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]);
            }
            // code here 
            int low = 0, high = n-1;
            int ans;
            while(low <= high) {
                int cut1 = low +(high-low)/2;
                int cut2 = n - cut1;
                
                int l1 = (cut1 == 0 ? INT_MIN : ar1[cut1-1]);
                int l2 = (cut2 == 0 ? INT_MIN : ar2[cut2-1]);
                int r1 = (cut1 == n ? INT_MAX : ar1[cut1]);
                int r2 = (cut2 == n ? INT_MAX : ar2[cut2]);
                
                if(l1 > r2){
                    high = cut1-1;
                }else if(l2 > r1) {
                    low = cut1+1;
                }else{
                    ans = max(l1,l2) + min(r1,r2);
                    break;
                }
            }
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends