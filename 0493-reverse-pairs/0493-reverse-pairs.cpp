class Solution {
public:

    void merge(vector<int> &nums, int left, int mid, int right){
        int i = left, j = mid + 1, k = 0;
        vector<int> temp(right - left + 1);

        while(i <= mid && j <= right){
            if(nums[i] < nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }

        while(i <= mid){
            temp[k++] = nums[i++];
        }

        while(j <= right){
            temp[k++] = nums[j++];
        }

        for(int i = left; i <= right; i++)
            nums[i] = temp[i-left];
    }

    int crossCount(const vector<int>& nums, int left, int mid, int right){
        int j = mid + 1;
        int ans = 0;

        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j])
                j++;

            ans += j - (mid + 1);
        }

        return ans;
    }

    int mergeSort(vector<int> &nums, int left, int right){
        int cnt = 0;
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;

        cnt+= mergeSort(nums, left, mid);
        cnt+=mergeSort(nums, mid + 1, right);
        cnt+=crossCount(nums, left, mid, right);
        merge(nums, left, mid, right);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};