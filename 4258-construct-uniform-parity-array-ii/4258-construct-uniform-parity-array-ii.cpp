class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_elem = nums1[0];
        bool odd = false;
        for(auto& x : nums1){
            min_elem = min(min_elem, x);
            odd |= x & 1;
        }

        return (min_elem & 1) == odd;
    }
};