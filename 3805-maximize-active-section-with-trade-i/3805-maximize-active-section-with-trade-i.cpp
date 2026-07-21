class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zeros;
        int zero_cnt = 0;
        for(char c : s){
            if(c == '0') ++zero_cnt;
            else if(zero_cnt) zeros.push_back(exchange(zero_cnt, 0));
        }

        if(zero_cnt) zeros.push_back(zero_cnt);

        int maxZero = 0;
        for(int i = 1; i < zeros.size(); i++){
            maxZero = max(maxZero, zeros[i - 1] + zeros[i]);
        }

        return ranges::count(s, '1') + maxZero;
    }
};