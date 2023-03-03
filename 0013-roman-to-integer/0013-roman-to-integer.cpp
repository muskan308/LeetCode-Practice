class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        unordered_map<string, int> roman1;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        roman1["IV"] = 4;
        roman1["XC"] = 90;
        roman1["IX"] =9;
        roman1["XL"] = 40;
        roman1["CD"] = 400;
        roman1["CM"] = 900;
        
        int ans = 0;
        string str ="";
        for(int i = 0; i < s.size() ;i++){
            str="";
           str += s[i];
            str+=s[i+1];
          //  cout << str<< " ";
           if(roman1.count(str)){
               cout << str<<" ";
               ans += roman1[str];
               i++;
           }else{
               ans += roman[s[i]];
           }
        }return ans;
    }
};