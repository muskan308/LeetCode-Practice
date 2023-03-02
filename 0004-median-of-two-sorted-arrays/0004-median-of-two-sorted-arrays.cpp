class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        int m = (n1+n2)/2;
        float ans;
        
        if(n2 < n1) return findMedianSortedArrays(nums2, nums1);
        
        int low = 0, high = n1;
        
        while(low <= high){
            int cut1 = low+(high-low)/2;
            int cut2 = m - cut1;
            
            float l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            float l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            float r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            float r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(l1 > r2){
                high = cut1-1;
            }else if(l2 > r1){
                low = cut1+1;
            }else{
                ans =(n1+n2)%2 == 0 ? (max(l1, l2) + min(r1, r2))/2 : min(r1,r2);
                break;
            }
            
        }
        return ans;
    }
};