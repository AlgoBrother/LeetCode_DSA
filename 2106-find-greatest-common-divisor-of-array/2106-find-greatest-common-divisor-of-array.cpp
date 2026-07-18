class Solution {
public:

    int max(vector<int>& arr){
        int max = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > max) max = arr[i];

        }
        return max;
    }

    int min(vector<int>& arr){
        int max = INT_MAX;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < max) max = arr[i];

        }
        return max;
    }

    int findGCD(vector<int>& nums) {
        int mAx = max(nums);
        int min_elem = min(nums);

        return gcd(mAx, min_elem);
    }
};