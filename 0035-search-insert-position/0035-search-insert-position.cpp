class Solution {
public:
    int binarySearch(vector<int> arr, int target){
        int right = arr.size()-1;
        int left = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        int pos = binarySearch(nums, target);
        int n = nums.size();
        if(pos == -1){
            int i = 0;
            while(n--){
                if(nums[i] > target){ pos = i;break;}
                else pos = nums.size();
                i++;
            }
        }
        return pos;
    }
};