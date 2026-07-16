class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i = 0 ; i < 2 * n; i++){
            int index = i % n;
            while(!stk.empty() && nums[index] > nums[stk.top()]){
                ans[stk.top()] = nums[index];
                stk.pop();
            }
            if (i < n) stk.push(index);
        }

   
        

        return ans;

    }
};