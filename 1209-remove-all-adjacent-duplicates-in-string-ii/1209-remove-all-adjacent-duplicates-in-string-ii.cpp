class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size() == 0) return "";
        stack<pair<char, int>> str;
        
        
        // str.push({s[0], 1});
        int i = 0;
     
        int n = s.size();
        while(i < n){
            //freq[s[i]] = freq[s[i]] ? freq[s[i]] : 1;
            if(str.empty()){
                str.push({s[i], 1});
            }else{
                if(str.top().first != s[i]){
                str.push({s[i], 1});
            }
            else{
               str.top().second += 1;
                if(str.top().second == k){
                    str.pop();
                }
               }
            }
            i++;
        }
        string st = "";
        stack<char> st1;
        while(!str.empty()){
            while(str.top().second != 0){
                st1.push(str.top().first);
                str.top().second--;
            }
            str.pop();
        }
        while(!st1.empty()){
            st += st1.top();
            st1.pop();
        }
        return st;
    }
};