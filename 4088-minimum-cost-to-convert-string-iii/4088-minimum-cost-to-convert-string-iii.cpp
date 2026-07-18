class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.length();
        int num_rules = rules.size();

        const long long INF = 1e16;
        vector<long long> dp(n + 1, INF);
        dp[0]= 0;

        vector<int> wildcards(rules.size(), 0);
        for(int i = 0; i < num_rules; ++i){
            for(char c : rules[i][0]){
                if(c == '*') wildcards[i]++;
            }
        }

        for(int i = 0; i < n; i++){
            if(dp[i] == INF) continue;

            if(source[i] == target[i]){
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            for(int r = 0; r < num_rules; ++r){
                const string pattern = rules[r][0];
                const string& replacement = rules[r][1];
                int len = pattern.length();

                if(i + len > n) continue;

                bool  matches = true;

                for(int j = 0; j < len; j++){
                    if(replacement[j] != target[i + j]){
                        matches = false;
                        break;
                    }

                    if(pattern[j] != '*' && pattern[j] != source[i + j]){
                        matches = false;
                        break;
                    }
                }

                if (matches){
                    long long curr_cost = (long long)costs[r] + wildcards[r];
                    dp[i + len] = min(dp[i + len], dp[i] + curr_cost);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};