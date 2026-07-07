
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cand2 = 1;
        int count1 = 0, count2 = 0;
        for(int &x: nums){
            if(x == cand1) count1++;
            else if(x == cand2) count2++;
            else if(count1 == 0){ 
                cand1 = x;
                count1 = 1;
            }
            else if(count2 == 0){
                cand2 = x;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int &x: nums){
            if(cand1 == x){
                count1++;
            } 
            if(x == cand2){
                count2++;
            }
        }

        vector<int> arr;
        
        if(count1 > nums.size() / 3){
            arr.push_back(cand1);
        } 
        if(count2 > nums.size() / 3){
            arr.push_back(cand2);
        }
        

        return arr;
    }
};