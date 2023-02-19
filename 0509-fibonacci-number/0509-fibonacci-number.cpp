class Solution {
public:
    // int mem[31] = {};
    int fib(int n) {
//         if(n == 0 || n == 1)return n;
//         if(mem[n]) return mem[n];
//         return mem[n] = fib(n-1)+fib(n-2);
        if(n == 0 || n ==1)return n;
        // vector<int> mem(n+1, -1);
        // mem[0] = 0;
        // mem[1] = 1;
        int a = 0, b =1;
        for(int i = 2; i <=n ; i++){
            int c = a + b;
            a = b;
            b = c;
            // mem[i] = mem[i-1]+mem[i-2];
        }
        return b;
    }
};