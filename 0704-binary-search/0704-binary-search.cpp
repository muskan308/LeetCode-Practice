class Solution {
public:
    
    int binSearch(vector<int> arr, int low, int high, int target ) {
        if(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[mid] == target) return mid;
            if(arr[mid] < target) return binSearch(arr, mid+1, high, target);
            else return binSearch(arr, low, mid-1, target);
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return binSearch(nums, 0, nums.size()-1, target);
    }
};