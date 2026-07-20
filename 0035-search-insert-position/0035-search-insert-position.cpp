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
        return left;
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target);
    }
};