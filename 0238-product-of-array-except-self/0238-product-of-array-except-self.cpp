class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMul(nums.size()), suffixMul(nums.size());
        prefixMul[0] = nums[0];
        suffixMul[n-1] = nums[n-1];
        for(int i = 1 ;i < n; i++){
            prefixMul[i] = prefixMul[i-1]*nums[i];
        }
        
        for(int j = n-2 ; j >=0 ; j--){
            suffixMul[j] = suffixMul[j+1]*nums[j];
        }
        
        nums[0] = suffixMul[1];
        nums[n-1] = prefixMul[n-2];
        
        for(int i = 1 ; i < n-1 ; i++){
            nums[i] = suffixMul[i+1]*prefixMul[i-1];
        }
        return nums;
    }
};