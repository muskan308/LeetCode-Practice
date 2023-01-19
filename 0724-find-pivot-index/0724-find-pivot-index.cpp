class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        vector<int> lrprefix(size), rlprefix(size);
        
        lrprefix[0] = nums[0];
        rlprefix[size-1] = nums[size-1];
        
        for(int i = 1; i < size; i++){
            lrprefix[i] = lrprefix[i-1] + nums[i];
            // cout << lrprefix[i] << " ";
        }
        
        for(int i = size-2 ; i >=0 ;i--){
            rlprefix[i] = rlprefix[i+1] + nums[i];
            // cout << rlprefix[i] << " ";
        }
        
        if(rlprefix[1] == 0) return 0;
       
        for(int i = 1; i < size-1; i++){
            if(lrprefix[i-1] == rlprefix[i+1]) return i;
        }
         if(lrprefix[size-2] == 0) return size-1;
        return -1;
        
    }
};