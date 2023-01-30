class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //2 3 -2 -4
        int maxPro = INT_MIN, l = 1 ,r =1;
        int size = nums.size()-1;
        for(int i = 0; i < nums.size() ;i++){
            l = (l? l:1)*nums[i];
            r = (r? r:1)*nums[size-i];
            maxPro = max(maxPro, max(l, r));
        }
        return maxPro;
    }
};