class Solution {
public:
    int minimumPushes(string word) {
        auto q = word.size() >> 3;
        auto r = word.size() & 7;
        return ((4 * q) + r) * (q + 1);  
    }
};