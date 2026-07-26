class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long modPower(long long a, long long e){
        long long r = 1;
        while(e){
            if(e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }

        return r;
    }
    
    int countValidSequences(int n, int k) {
        vector<long long> fact(n + 1), invFact(n + 1);
        fact[0] = 1;
        for(int i = 1; i <= n; i++){
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = modPower(fact[n], MOD-2);
        for(int i = n; i >= 1; i--) invFact[i - 1] = invFact[i] * i % MOD;

        auto C = [&](int N, int R) -> long long {
            if(R < 0 || R > N) return 0;
            return fact[N] * invFact[R] % MOD * invFact[N - R] % MOD;
        };

        long long total = C(n - 1, k-1);
        long long odd = 0;
        if((n - k) % 2 == 0){
            int m = (n - k) / 2;
            odd = C(m + k - 1, k -1);
        }
        return (total - odd + MOD) % MOD;
    }
};