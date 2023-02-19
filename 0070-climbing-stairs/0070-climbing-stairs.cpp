class Solution {
public:
    int ans(int n, vector<int> &mem){
        if(n == 0)return 1;
        if(n < 0) return 0;
        if(mem[n] != -1)return mem[n];
        return mem[n] = ans(n-1, mem) + ans(n-2, mem);
    }
    int climbStairs(int n) {
        vector<int> mem(n+1, -1);
        return ans(n , mem);
    }
};