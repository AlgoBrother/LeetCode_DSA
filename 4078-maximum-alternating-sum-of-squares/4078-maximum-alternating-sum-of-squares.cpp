class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] *= nums[i];
        }
        std::sort(nums.begin(),nums.end());

    
        int mid = nums.size() / 2;
;

        long long score = 0;
        for(int i = 0; i < mid; i++) score -= nums[i];
        for(int i = mid; i < nums.size(); i++) score += nums[i];

        return score;

    }
};