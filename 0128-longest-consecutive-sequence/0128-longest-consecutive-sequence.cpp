class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;
        for(auto &x : nums) st.insert(x);
        int longest = 1;
        for(auto &elem : st){
            if(st.find(elem - 1) == st.end()){
                int count = 1;
                int x = elem;
                while(st.find(x + 1) != st.end()){
                    x += 1;
                    count++;
                }
                longest = max(longest, count);
            }
        }

        return longest;


    }
};