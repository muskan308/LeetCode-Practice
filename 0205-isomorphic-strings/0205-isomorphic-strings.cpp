class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, char> mappst, mappts;
        for(int i = 0 ;i < s.size() ; i++){
            if(mappts.find(t[i]) != mappts.end() && mappts[t[i]] != s[i]){
                cout << t[i] << " "<<s[i];
                return false;
            }else if(mappst.find(s[i]) != mappst.end()  && mappst[s[i]] != t[i]){
                return false;
            }
            else{
                mappts[t[i]] = s[i];
                mappst[s[i]] = t[i];
                // mapp[t[i]] = s[i];
            }
        }
        return true;
    }
};