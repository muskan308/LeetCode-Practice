class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
         vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(size < 3)return ans;
        if(nums[0] > 0 )return {};
        
        for(int i = 0; i <  size ; i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int first = nums[i];
            if(first > 0) break;
          
                
            int low = i+1, high = size-1;
            while(low < high){
                if(first + nums[low] + nums[high] == 0){
                    ans.push_back({first, nums[low], nums[high]});
                    low++;high--;
                    while(low < size && nums[low] == nums[low-1]) low++;
                    while(high > i && nums[high] == nums[high+1]) high--;
                    
                }else if(first + nums[low] + nums[high] <0){
                    low++;
                }else{
                    high--;
                }
            }
        }return ans;
    }
};