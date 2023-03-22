//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    void reverse(string &str){
        int i = 0, j = str.size()-1;
        while(i < j){
            swap(str[i], str[j]);
            i++;j--;
        }
    
    }
    string reverseWords(string S) 
    { 
        // code here
        
        // S += '.';
        reverse(S);
        S += '.';
        // cout << S<<" ";
        stringstream ss(S);
        string str = "";
        getline(ss, str, '.');
        string ans = "";
        
        while(str.size() != 0){
            reverse(str);
            // cout << str << " ";
            ans = ans + str;
            getline(ss, str, '.');
            if(str != "") ans += ".";
        }
      return ans;  
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends