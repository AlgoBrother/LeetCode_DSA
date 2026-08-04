class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        vector<bool> exists(101);   
        int min = INT_MAX;
        int max = INT_MIN;

        for(int& ele : nums){
            if(ele > max) max = ele;
            if(ele < min) min = ele;
            exists[ele] = true;
        }

        for(int i = min; i <= max; i++){
            if(exists[i] == false) ans.push_back(i);
        }

        return ans;
    }
};