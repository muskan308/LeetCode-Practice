class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        if(nums.size() == 1) return nums[0];
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(mid == 0 && nums[mid]<nums[mid+1]) return nums[mid];
            if(mid == nums.size()-1 && nums[mid] < nums[mid-1]) return nums[mid];
            if((mid!=0 && nums[mid] < nums[mid-1]) &&( mid!= nums.size()-1 && nums[mid] < nums[mid+1])) return nums[mid];
            else if((mid!=0 && nums[mid] > nums[mid-1]) && nums[low] < nums[mid]){
                if(nums[low] < nums[high]) return nums[low];
                else low = mid+1;
            }else{
                if((mid!= nums.size()-1 && nums[mid+1] < nums[mid] )) return nums[mid+1];
                else high = mid-1;
            }
      }return 0;
    }
};