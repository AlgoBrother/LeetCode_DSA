class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        while(n > 0){
            int rem = n % 10;
            if(rem == 0)
            {
                n /= 10;
                continue;
            }else{
                x = (x * 10) + rem;
                n /= 10;
            }
        }

        long long temp_x = 0;
        while(x > 0){
            int rem = x % 10;
            temp_x = (temp_x * 10) + rem;
            x /= 10;
        }

        x = temp_x;

        long long sum = 0;
        long long temp = x;
        while(temp > 0){
            int rem = temp % 10;
            sum += rem;
            temp /= 10;
        }
        return sum * x;
    }
};