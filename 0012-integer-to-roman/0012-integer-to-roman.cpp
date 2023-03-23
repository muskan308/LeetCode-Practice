class Solution {
public:
    unordered_map<int, string> romans;
    Solution(){
        romans[1] = "I";
        romans[4] = "IV";
        romans[5] = "V";
        romans[9] = "IX";
        romans[10] = "X";
        romans[40] = "XL";
        romans[50] = "L";
        romans[90] = "XC";
        romans[100] = "C";
        romans[400] = "CD";
        romans[500] = "D";
        romans[900] = "CM";
        romans[1000] = "M";
    }
 
    string intToRoman(int num) {
        int places = 0;
        string ans = "";
        stack<string> st;
        while(num){
            cout << "He";
            int rem = num%10;
            int val = rem * pow(10,places);
            if(romans.count(val)){
                // ans += romans[val];
                st.push(romans[val]);
            }else{
                string str = "";
                if(val > 5*pow(10,places)){
                    str += romans[5*pow(10,places)];
                    // st.push(romans[5*pow(10,places)]);
                    rem = rem-5;  
                }
                for(int i = 0; i < rem ; i++){
                    str += romans[1*pow(10,places)];
                    
                    // st.push(str);
                }
                st.push(str);
            }
            places++;
            num = num/10;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};