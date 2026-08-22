class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int x = n;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }

        int prod = 1;
        x = n;
        while(x > 0){
            prod *= x % 10;
            x /= 10;
        }

        int finalSum = sum + prod;

        if(n % finalSum != 0) return false;
        return true;
    }
};