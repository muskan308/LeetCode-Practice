class Solution {
public:
    
    int mha(vector<int> arr, int n){
        stack<int> st;
        vector<int> ps(n);
        int curr, ma = INT_MIN;
        for(int i = 0; i < n ; i++){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                curr = arr[st.top()] * (i - (ps[st.top()]+1) );
                ma = max(ma, curr);
                st.pop();
            }
            if(st.empty()){
                ps[i] = -1;
            }else{
                ps[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            curr = arr[st.top()] * (n -( ps[st.top()]+1) );
                ma = max(ma, curr);
                st.pop();
        }
        return ma;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ma = INT_MIN;
        vector<int> send(m,0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;j < m ; j++){
               // cout << "matrix : "<< matrix[i][j] << endl;
                if(matrix[i][j] == '0'){
                    send[j] = 0;
                    //cout << "send[j] "<< send[j]<< " ";
                }else{
                    send[j] +=1;
                }
            }
           // for(int k = 0; k < m ; k++)cout << send[k] << " ";
            ma = max(ma, mha(send, m));
        }return ma;
        // vector<int> arr = {4,0,0,1,0};
        // return mha(arr, 5);
    }
};