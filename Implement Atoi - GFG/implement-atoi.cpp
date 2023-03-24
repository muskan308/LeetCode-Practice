//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans = 0;
       
        int i =0 ;
        bool neg = false;
        if(str[0] == '-'){
            neg = true;
             i =1;
        }
        for(; i < str.size() ; i++){
            if(!(str[i] >= '0' && str[i] <= '9')){
                return -1;
            }else{
                
                 ans = ans*10 + str[i]-'0';
            }
        }
        
        return neg ? 0-ans : ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends