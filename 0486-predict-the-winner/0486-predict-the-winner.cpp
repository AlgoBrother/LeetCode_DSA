class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size() % 2 == 0) return true;
        vector<int> dp(nums);

        for(int i = nums.size() - 2; i >= 0; i--){
            for(int j = i + 1; j < nums.size(); j++){
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }

        return dp[nums.size() - 1] >= 0;
    }
};