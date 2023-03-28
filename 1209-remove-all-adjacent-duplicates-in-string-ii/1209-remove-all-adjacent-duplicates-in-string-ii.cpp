class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size() == 0) return "";
        vector<pair<char, int>> str;
        
        
      
        int i = 0;
     
        int n = s.size();
        while(i < n){
            
            if(str.empty()){
                str.push_back({s[i], 1});
            }else{
                if(str.back().first != s[i]){
                str.push_back({s[i], 1});
            }
            else{
               str.back().second += 1;
                if(str.back().second == k){
                    str.pop_back();
                }
               }
            }
            i++;
        }
        string st = "";
       
        for(int i = 0; i < str.size() ; i++){
            while(str[i].second != 0){
                st += str[i].first;
                str[i].second--;
            }
            
        }
    
        return st;
    }
};