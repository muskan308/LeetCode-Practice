class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<int> st1, st2;
        
        for(int i = 0; i < num1.size() ; i++){
            st1.push(num1[i]-'0');
        }
        for(int i = 0; i < num2.size(); i++){
            st2.push(num2[i]-'0');
        }
        int carry =0;
        
        stack<int> ans;
        while(!st1.empty() && !st2.empty()){
            int a = st1.top(), b = st2.top();
            st1.pop(); st2.pop();
            int val = a+b+carry;
            carry = val/10;
            ans.push(val%10);
        }
        while(!st1.empty()){
            int val = st1.top()+carry;
            ans.push(val%10);
            carry = val/10;
            st1.pop();
        }
        while(!st2.empty()){
            int val = st2.top()+carry;
            ans.push(val%10);
            carry = val/10;
            st2.pop();
        }
        if(carry!=0) ans.push(carry);
        string str ="";
                     while(!ans.empty()){
                         str+= to_string(ans.top());
                         ans.pop();
                     }
                     return str;
    }
};