class Solution {
public:
    int mem[31] = {};
    int fib(int n) {
        if(n == 0 || n == 1)return n;
        if(mem[n]) return mem[n];
        return mem[n] = fib(n-1)+fib(n-2);
    }
};