class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1000, max2 = -1000, max3 = -1000;
        int min1 = 0, min2 = 0;

        for(int& x : nums){
            if(min1 >= x){
                min2 = min1;
                min1 = x;
            }else if(min2 >= x) min2 = x;
            
            if(max1 <= x){
                max3 = max2;
                max2 = max1;
                max1 = x;
            }else if(max2 <= x){
                max3= max2;
                max2 = x;
            }else if(max3 <= x) max3 = x;
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};