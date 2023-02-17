//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    sort(arr, arr+size);
    
    if(n ==0){
        for(int i = 1; i < size; i++) if(arr[i] == arr[i-1])return true;
        return false;
    }
    
    for(int k = 0; k < size ; k++){
        int i = 0, j = size-1;
        while(i <= j){
            int mid = i+(j-i)/2;
            if(arr[k]-arr[mid] == n)return true;
            else if(arr[k]-arr[mid] < n) j = mid-1;
            else i = mid+1;
        }
    }
    return false;
}