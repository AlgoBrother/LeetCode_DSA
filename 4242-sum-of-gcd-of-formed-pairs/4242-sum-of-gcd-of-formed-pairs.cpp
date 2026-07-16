class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int left = 0;
        int max = INT_MIN;
        int right = nums.size() - 1;
        vector<int> prefixGcd(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(max < nums[i]) max = nums[i];
            prefixGcd[i] = gcd(nums[i], max);
        }

        std::sort(prefixGcd.begin(), prefixGcd.end());
       long long sum = 0;
        while (left < right){
            sum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return sum;
    }
};