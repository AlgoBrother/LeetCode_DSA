class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;
        vector<vector<int>> dp(4, vector<int>(MAXX, false));
        dp[0][0] = true;

        for(int pick = 0; pick < 3; pick++){
            for(int i = 0; i < MAXX; i++){
                if(!dp[pick][i]) continue;
                for(int v : nums){
                    dp[pick + 1][i ^ v] = true;
                }
            }
        }

        int ans = 0;

        for(bool ok : dp[3]){
            ans += ok;
        }

        return ans;

    
    }
};