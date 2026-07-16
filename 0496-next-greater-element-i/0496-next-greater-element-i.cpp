class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> mp;
        for(int &x : nums2){
            while(!stk.empty() && x > stk.top()){
                mp[stk.top()] = x;
                stk.pop();
            }
            stk.push(x);
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            int x = nums1[i];
            if(mp.find(x) != mp.end()){
                ans[i] = mp[x];
            }else{
                ans[i] = -1;
            }
        }
        return ans;
    }
};