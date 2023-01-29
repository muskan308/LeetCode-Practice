//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        unordered_map<int, int> index;
        
        for(int i = 0; i < N ;i ++){
            if(arr[i] == 0) arr[i] = -1;
        }
        
        int prefixSum = 0;
        int max_len = 0;
        
        for(int i = 0; i < N ; i++){
            prefixSum += arr[i];
            if(prefixSum == 0) max_len = i+1;
            if(index.count(prefixSum) == 0){
                index[prefixSum] = i;
            }else{
                max_len = max(max_len, i - index[prefixSum]);
            }
        }
        return max_len;
    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends