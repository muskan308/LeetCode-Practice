class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size() == 0) return "";
        deque<pair<char, int>> str;
        
        
        // str.push({s[0], 1});
        int i = 0;
     
        int n = s.size();
        while(i < n){
            //freq[s[i]] = freq[s[i]] ? freq[s[i]] : 1;
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
        // stack<char> st1;
        while(!str.empty()){
            while(str.front().second != 0){
                // st1.push(str.top().first);
                st += str.front().first;
                str.front().second--;
            }
            str.pop_front();
        }
        // while(!st1.empty()){
        //     st += st1.top();
        //     st1.pop();
        // }
        return st;
    }
};