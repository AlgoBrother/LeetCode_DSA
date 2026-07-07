class Solution {
public:
    void merge(std::vector<int>& nums1, std::vector<int>& nums2){
        int i = 0, j =0, k = 0;
        std::vector<int> temp(nums1.size() + nums2.size());
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                temp[k++] = nums1[i++];
            }else{
                temp[k++] = nums2[j++];
            }
        }

        for(; i < nums1.size(); i++){
            temp[k++] = nums1[i];
        }
        for(; j < nums2.size(); j++){
            temp[k++] = nums2[j];
        }

        nums1 = temp;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        merge(nums1, nums2);
        int n = nums1.size();
        if (n % 2 != 0) {
            return nums1[n / 2];
        } else {
            return (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
        }
    }
};