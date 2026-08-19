class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = 0;
        vector<bool> freq(201, 0);
        for(int &i : nums){
            sum += i;
            freq[i + 100] = 1;
        }

        double avg = sum / (double)nums.size();

        for(int i = 101; i < 201; i++){
            if(freq[i] == 0 && avg < (i - 100)) return i - 100;
        }
        return 101;
    }
};