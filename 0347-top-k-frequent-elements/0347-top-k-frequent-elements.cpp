class Solution {
public:
    static bool myCmp(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
    
    vector<int> sort1(unordered_map<int, int> &count, int k){
        vector<pair<int, int>> forSort(count.size());
        int i = 0;
        for(auto x : count){
            forSort[i].first = x.first;
            forSort[i].second = x.second;
            i++;
        }
        
        sort(forSort.begin(), forSort.end(), myCmp);
        
        vector<int> ans;
        
        for(int i = 0; i < k; i++){
            ans.push_back(forSort[i].first);
        }
        return ans;
    }
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        
        for(int i = 0; i < nums.size() ; i++){
            count[nums[i]]++;
        }
        
        return sort1(count, k);
        
    }
};