class Solution {
public:
    int binSearch(vector<int> arr, int low, int high, int target) {
        int mid;
        
        while(low <= high) {
             mid = low+(high-low)/2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] < target) {
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        // if(low > arr.size()-1) return high;
        return low;
    }
    int searchInsert(vector<int>& nums, int target) {
        return binSearch(nums, 0, nums.size()-1, target);
    }
};