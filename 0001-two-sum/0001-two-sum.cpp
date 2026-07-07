class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ourMAP;
        for(int i = 0 ; i< nums.size(); i++){
            int complement = target - nums[i];
            if(ourMAP.count(complement)){
                return {ourMAP[complement], i};
            }
            ourMAP[nums[i]] = i;
        } 
        return {};
    }
};