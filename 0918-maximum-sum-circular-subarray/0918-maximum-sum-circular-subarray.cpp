class Solution {
    
    
    int kadane(vector<int> arr) {
        int curr = arr[0],max_sum = arr[0];
        
        for(int i = 1; i < arr.size() ; i++){
            if(curr <0) curr = 0;
            
            curr += arr[i];
            
            max_sum = max(max_sum, curr);
            // cout <<" *"<< max_sum << "* ";
        }
        return max_sum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum = 0, ifpos = 0;
        
        for(auto x : nums) {
            totalsum += x;
            if(x > 0 ) ifpos = 1;
        }
        if(ifpos == 0) return kadane(nums);
        vector<int> arr = nums;
       for(int i = 0; i < nums.size() ; i++){
           nums[i] *= -1;
       }
        // for(auto x: nums){
        //     cout << x <<" ";
        // }
        
        int min_sum = kadane(nums);
        // cout << min_sum<<" ";
        return max(totalsum + min_sum, kadane(arr));
        
    }
};