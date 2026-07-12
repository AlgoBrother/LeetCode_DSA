class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        vector<int> rank(arr.size());
        for(int i = 0; i < arr.size(); i++){
            rank[i] = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin()  + 1;
        }
        return rank;
    }
};