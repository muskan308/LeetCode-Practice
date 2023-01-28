class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        //4 5 8 // 1 8 9 10
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for(int i = 0; i < arr1.size() ; i++){
            int low = 0, high = arr2.size();
            while(low <= high){
                int mid = low + (high-low)/2;
            if(abs(arr1[i] - arr2[mid]) <= d) {
                ans++;
                break;
            }
            if((arr1[i] - arr2[mid]) < 0) high = mid-1;
            else if((arr1[i] - arr2[mid]) >0) low = mid+1;
            }
        }
        return arr1.size()-ans;
    }
};