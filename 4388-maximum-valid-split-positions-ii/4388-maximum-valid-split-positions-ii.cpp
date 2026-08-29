class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> P(n), S(n);
        P[0] = nums[0];
        for(int i = 1; i < n; ++i) P[i] = gcd(P[i-1], nums[i]);
        S[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; --i) S[i] = gcd(S[i + 1], nums[i]);

        int temp = 18;
        vector<vector<int>> st(temp, vector<int>(n));
        st[0] = nums;
        for(int j = 1; j < temp; ++j){
            for(int i = 0; i + (1 << j) <= n; ++i){
                st[j][i] = gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }

        auto query = [&](int L, int R){
            int temP = 31 - __builtin_clz(R - L + 1);
            return gcd(st[temP][L], st[temP][R - (1 << temP) + 1]);
        };

        auto getL = [&](int g) -> int{
            return lower_bound(P.begin(), P.end(), g, greater<int>()) - P.begin();
        };

        auto getR = [&](int g) -> int{
            return upper_bound(S.begin(), S.end(), g) - S.begin() - 1;
        };

        int ans = std::max(0, (int)(getR(P[n-1])) - getL(P[n - 1]));

        for(int k = 0; k < n; k++){
            int p_prev = (k > 0) ? P[k-1] :0;
            int s_next = (k < n - 1) ? S[k + 1] : 0;
            int g = gcd(p_prev, s_next);

            int L_prime, R_prime;
            if(k > 0 && p_prev == g){
                L_prime = getL(g);
            }else{
                
                int low = k + 1, high = n - 1;
                
                L_prime = n  - 1;
                while(low <= high){
                    int mid = low + (high - low)/2;
                    if(gcd(p_prev, query(k + 1, mid)) <= g){
                        L_prime = mid;
                        high = mid - 1;
                    }else low = mid + 1;
                }
            }

            if(k < n-1 && s_next == g){
                R_prime = getR(g);
            }else{
                int low = 0, high = k -1;
                R_prime = 0;
                while(low <= high){
                     int mid = low + (high - low)/2;
                    if(gcd(s_next, query(mid, k - 1)) <= g){
                        R_prime=mid;
                        low=mid+1;
                    }else high = mid - 1;
                }
            }

            if(R_prime >= L_prime){
                int score = R_prime - L_prime - (L_prime < k && k < R_prime ? 1 : 0);
                ans = max(ans, score);
            }
        }
        return ans;
    }
};