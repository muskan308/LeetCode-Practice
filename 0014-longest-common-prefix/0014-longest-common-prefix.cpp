class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        for(int i = 1; i < strs.size() ; i++){
            int j;
            for(j = 0; j < str.size() ; j++){
                if(str[j] != strs[i][j]){
                    break;
                }
            }
            str = str.substr(0, j);
        }
        return str;
    }
};