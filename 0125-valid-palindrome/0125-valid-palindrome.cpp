class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i = 0; i < s.size() ; i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                str += s[i];
            }else if(s[i] >= 'A' && s[i] <= 'Z'){
                str += tolower(s[i]);
            }        }
        int size = str.size()-1;
        int i = 0 , j = size;
        cout << str;
        while(i <= j){
            if(str[i] != str[j]) return false;
            i++;j--;
        }
        return true;
    }
};