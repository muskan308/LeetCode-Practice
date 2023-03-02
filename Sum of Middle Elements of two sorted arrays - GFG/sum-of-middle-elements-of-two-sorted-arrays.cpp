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
            if(n==1) return ar1[0] + ar2[0];
  if(n == 2) return max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]);
  
  int i = 0, j = 0;
  int k = 0;
  int merged[2*n];
  
  while(i < n && j < n){
    if(ar1[i] <= ar2[j]){
      merged[k] = ar1[i];
      i++;k++;
    }else{
      merged[k] = ar2[j];
      j++;k++;
    }
  }
  while(i < n){
    merged[k] = ar1[i];
    i++;k++;
  }
  while(j < n){
    merged[k] = ar2[j];
    j++;k++;
  }
  
  return merged[n] + merged[n-1];
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