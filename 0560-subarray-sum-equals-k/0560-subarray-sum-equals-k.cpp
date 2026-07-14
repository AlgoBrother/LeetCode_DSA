class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        int ans = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;

        for(int &x: nums){
            prefix += x;
            if(freq.count(prefix - k)){
                ans += freq[prefix - k];
            }
            freq[prefix]++;
            
        }
        return ans;
    }
};