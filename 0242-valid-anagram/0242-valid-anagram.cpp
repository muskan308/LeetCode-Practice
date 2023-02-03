class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> anagram;
        for(int i = 0; i < s.size() ; i++){
            anagram[s[i]]++;
        }
        
        for(int i = 0; i < t.size() ; i++){
            if(anagram.count(t[i]) == 0) return false;
            else{
                anagram[t[i]]--;
                if(anagram[t[i]]==0) anagram.erase(t[i]);
            }
        }
        
        return anagram.size()==0;
    }
};