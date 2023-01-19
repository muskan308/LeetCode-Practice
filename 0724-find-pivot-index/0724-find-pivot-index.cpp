class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        
        int Sum = 0, preSum =0;
        for(auto x: nums){
            Sum += x;
        }
       
        
        for(int i = 0; i < size; i++){
            
           if(Sum - preSum - nums[i] == preSum ){
               return i;
           }
            preSum += nums[i];
        }
         
        return -1;
        
    }
};