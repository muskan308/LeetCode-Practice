class Solution {
public:
    bool ans(long long low, long long high, long long num) {
        // int low = 1 , high = num;
        
        while(low <= high) {
            long long mid = low + (high-low)/2;
            
            if(num == (mid*mid)) return true;
            if(num < (mid*mid)) return ans(low, mid-1, num);
            else return ans(mid+1, high, num);
        }
        return false;
    }
    
    bool isPerfectSquare(int num) {
        return ans(1, num, num);
    }
};