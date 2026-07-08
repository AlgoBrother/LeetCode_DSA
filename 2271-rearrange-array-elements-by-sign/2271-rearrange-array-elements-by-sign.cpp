class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos(nums.size() / 2);
        int pos_count = 0;
        int neg_count = 0;
        vector<int> neg(nums.size() / 2);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                pos[pos_count] = nums[i];
                pos_count++;
            } else{
                neg[neg_count] = nums[i];
                neg_count++;
            }
        }
        pos_count = 0;
        neg_count = 0;

        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                ans[i] = pos[pos_count];
                pos_count++;
            } else{
                ans[i] = neg[neg_count];
                neg_count++;
            }
        }
        return ans;
    }
};