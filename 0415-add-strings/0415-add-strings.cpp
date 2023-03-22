class Solution {
public:
    string addStrings(string num1, string num2) {
        //stack<int> st1, st2;
        
        int i = num1.size()-1, j = num2.size()-1;
        // for(int i = 0; i < num1.size() ; i++){
        //     st1.push(num1[i]-'0');
        // }
        // for(int i = 0; i < num2.size(); i++){
        //     st2.push(num2[i]-'0');
        // }
        string str ="";
        int carry =0;
        while(i >= 0 || j >= 0 || carry){
            int a = (i>=0 ? num1[i]-'0' : 0), b = (j >=0 ? num2[j]-'0' :0);
            i--;j--;
            int val = a+b+carry;
            carry = val/10;
            str+= to_string(val%10);
        }
        
        for(int k = 0; k < str.size()/2 ;k++){
            swap(str[k], str[str.size()-1-k]);
        }
                    
        return str;
    }
};