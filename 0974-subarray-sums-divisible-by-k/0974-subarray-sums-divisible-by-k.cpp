class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mods(k);
        mods[0] = 1;
        int prefixSum = 0, res = 0;
        
        for(auto x : nums) {
            prefixSum = ((prefixSum + x%k + k)%k);
            
            res += mods[prefixSum];
            
            mods[prefixSum]++;
            
        }
        return res;
    }
};