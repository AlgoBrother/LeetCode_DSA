class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long total = 0;
        long long count1 = 0, count2 = 0;

        for(int& num: nums){
            if(num < a){
                total += (count1 + count2);
            }else if(num >= a && num <= b){
                total+=count2;
                count1++;
            }else{
                count2++;
            }
        }

        long long MOD = 1e9 + 7;
        return total % MOD;
    }
};