class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int& i : nums){
            mp[i]++;
        }

        int n = nums.size();
        if(k == n) return *max_element(nums.begin(), nums.end());
        if(k == 1){
            int ans = -1;
            for(int i = 0; i < n ; i++){
                if(mp[nums[i]] == 1 && nums[i] > ans) 
                    ans = nums[i];
            }
            return ans;
        }

        n = n - 1;

        if(nums[0] == nums[n]) return -1;

        if(mp[nums[0]] == 1 && mp[nums[n]] == 1) return max(nums[0], nums[n]);

        if(mp[nums[0]] == 1 && mp[nums[n]] > 1) return nums[0];
        if(mp[nums[n]] == 1 && mp[nums[0]] > 1) return nums[n];

        return -1;
    }
};