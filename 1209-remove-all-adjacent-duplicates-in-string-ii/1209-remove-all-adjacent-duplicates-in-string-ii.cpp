class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size() == 0) return "";
        deque<pair<char, int>> str;
        
        
      
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
       
        while(!str.empty()){
            while(str.front().second != 0){
                st += str.front().first;
                str.front().second--;
            }
            str.pop_front();
        }
    
        return st;
    }
};