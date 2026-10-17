class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b; 
        b = temp;
    }

    int minSwaps(vector<int>& nums) {
        auto digit_sum = [](int x){
            int s = 0;
            for(; x > 0; x /= 10) s += x % 10;
            return s;
        };

        vector<pair<int, int>> keys;
        for(int& x : nums){
            keys.emplace_back(digit_sum(x), x);
        }

        ranges::sort(keys);
        unordered_map<int, int> rank;
        for(int k = 0; k < nums.size(); k++){
            rank[keys[k].second] = k;
        }

        vector<int> home;
        for(int& x : nums) home.push_back(rank[x]);


        int swaps = 0;
        for(int i = 0; i < nums.size(); i++){
            while(home[i] != i){
                int j = home[i];
                swap(home[i], home[j]);
                swaps++;
            }
        }

        return swaps;
    }
};