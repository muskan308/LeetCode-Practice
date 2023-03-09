class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int> &arr, int sid, int n){
        if(sid == n){
            ans.push_back(arr);
        }
        
        for(int i = sid ;i < n ;i++){
            swap(arr[i], arr[sid]);
            solve(arr, sid+1, n);
            swap(arr[i], arr[sid]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0, nums.size());
        return ans;
    }
};