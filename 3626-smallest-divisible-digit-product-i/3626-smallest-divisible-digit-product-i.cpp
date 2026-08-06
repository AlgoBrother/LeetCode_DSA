class Solution {
public:
    int kuchMila(int n){
        int x = n;
        int prod = 1;
        while(x > 0){
            int digit = x % 10;
            prod *= digit;
            x /= 10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {

        for(int i = n; i < n + 10; i++){
            if(kuchMila(i) % t == 0) return i;
        }
        return 0;
    }
};