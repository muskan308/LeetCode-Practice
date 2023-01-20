class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int low = 0, high = arr.size()-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(mid == 0){
                if(arr[mid+1] < arr[mid]) return mid;
                else low = mid+1;
            } 
            else if(mid == arr.size()-1) {
                 if(arr[mid-1] < arr[mid])
                    return mid;    
                else high = mid-1;
            }
            else if (arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid]) return mid;
            else if(arr[mid - 1]< arr[mid]) low = mid+1;
            else high = mid-1;
            
        }
        return 0;
    }
};