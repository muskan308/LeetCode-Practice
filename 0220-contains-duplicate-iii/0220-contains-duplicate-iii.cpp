class Solution {
public:
    
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        vector<pair<int, int>> pairs(n);
        
        for(int i = 0; i < n; i++){
            pairs[i].first = nums[i];
            pairs[i].second = i;
        }
        sort(pairs.begin(), pairs.end());
        
        for(int j = 0 ; j < n ; j++){
            for(int i = j+1 ; i < n && (pairs[i].first-pairs[j].first) <= valueDiff ; i++){
                if(pairs[i].first - pairs[j].first <= valueDiff){
                    if(abs(pairs[i].second - pairs[j].second) <= indexDiff){
                        return true;
                    }
                }
        }
        }
       return false;
    }
};