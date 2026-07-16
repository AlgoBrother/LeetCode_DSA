class Solution {
public:
    int nextGreaterElement(int n) {
        string n_s = to_string(n);
        bool val = next_permutation(n_s.begin(), n_s.end());
        long long n_l = stoll(n_s);
        if (!val) {
            return -1;
        }
        if(n_l > INT_MAX){
            return -1;
        }
         return (int)n_l;
    }
};