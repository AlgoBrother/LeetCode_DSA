class Solution {
public:
    int binarySearch(vector<int> arr, int target, bool searchLeft){
        int index = -1;
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] > target) right = mid - 1;
            else if(arr[mid] < target) left = mid + 1;
            else{
                index = mid;
                if(searchLeft){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }
        return index;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;
    }
};