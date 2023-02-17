class Solution {
public:
    
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<int, int>> pairs;
        
        for(int i = 0; i < nums.size() ; i++){
            pairs.push_back({nums[i], i});
        }
        sort(pairs.begin(), pairs.end());
        for(int i = 0; i < pairs.size() ; i++){
            cout << pairs[i].first << " "<<pairs[i].second<< endl;
        }
        for(int j = 0 ; j < nums.size() ; j++){
            for(int i = j+1 ; i < nums.size() && (pairs[i].first-pairs[j].first) <= valueDiff ; i++){
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