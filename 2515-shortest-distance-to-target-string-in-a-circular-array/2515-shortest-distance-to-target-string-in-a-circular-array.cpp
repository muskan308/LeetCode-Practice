class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        map<string, int> dist;
        int n = words.size();
        for(int i = 0; i < n ; i++)dist[words[i]] = INT_MAX;
        for(int i = 0; i < n ; i++){
            int diff = startIndex > i ? i-startIndex : startIndex-i;
            int val = min(abs(startIndex - i), ((diff) + n)%n);
            dist[words[i]] = min(dist[words[i]], val);
        }
        return dist.count(target) ? dist[target] : -1;
    }
};