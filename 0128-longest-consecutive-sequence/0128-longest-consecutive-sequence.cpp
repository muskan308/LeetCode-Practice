class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> consecutive;
        
        for(int i =0 ;i < nums.size() ; i++){
            consecutive.insert(nums[i]);
        }
        
        
        int res = 1, maxres = 1;
        for(auto x : consecutive){
            res = 1;
            if(consecutive.find(x-1)==consecutive.end()){
                int curr = x;
                while(consecutive.count(curr+1)){
                    res++;
                    curr ++;
                }
                maxres = max(res, maxres);
            }
        }
        return maxres;
    }
};