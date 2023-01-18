int kadane(vector<int>& nums){
    int n = nums.size();
    int currSum = 0, max1 = INT_MIN;
    for(int i = 0; i < n; i++ ){
        currSum += nums[i];
        max1 = max(max1, currSum);
        if(currSum < 0) currSum = 0;
        
    }
    return max1;
}

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int nonwrapsum = kadane(nums);
        if(nonwrapsum < 0){
            return nonwrapsum;
        }
        int wrapsum;
        int total = 0;
        for(int i = 0; i < n; i++){
            total += nums[i];
            nums[i] = -nums[i];
        }
        
        wrapsum = total + kadane(nums);
        return max(wrapsum, nonwrapsum);
    }
};