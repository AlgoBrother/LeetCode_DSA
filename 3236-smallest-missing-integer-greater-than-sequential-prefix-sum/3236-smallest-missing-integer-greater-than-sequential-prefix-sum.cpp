class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1] + 1){
                sum += nums[i];
            }else{
                break;
            }
        }

        vector<bool> ht(1276, false);
        for(int num : nums) ht[num] = true;

        while(ht[sum]) sum++;

        return sum;
    }
};