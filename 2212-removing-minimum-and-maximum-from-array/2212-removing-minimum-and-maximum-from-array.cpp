class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int low = min_element(nums.begin(), nums.end()) - nums.begin();
        int high = max_element(nums.begin(), nums.end()) - nums.begin();

        if (low > high) swap(low, high);

        return min({
            high + 1,
            n - low,
            low + 1 + n - high
        });
    }
};