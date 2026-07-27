class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;

        for (int& x : nums){
            if(x - 1 > max1){
                max2 = max1;
                max1 = x - 1;
            }else if(max2 < x){
                max2 = x - 1;
            }
        }

        return max1 * max2;
    }
};