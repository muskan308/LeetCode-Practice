//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<string> st;
        S += ".";
        string str ="";
        stringstream ss(S);
        getline(ss, str,'.');
        
        while(str.size() != 0){
            st.push(str);
            getline(ss, str, '.');
        }
        
        str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
            if(!st.empty()) str+= ".";
            
        }
        return str;
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