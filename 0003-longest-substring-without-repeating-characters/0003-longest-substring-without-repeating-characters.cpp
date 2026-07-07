class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int left = 0;
         int maxLength = 0;
        int seen[128] = {0};
         for(int i = 0; i < s.length(); i++){
            int currentChar = s[i];
            seen[currentChar]++;

            while(seen[currentChar] > 1){
                seen[s[left]]--;
                left++;
            }

            maxLength = std::max(maxLength, i - left + 1);
         }

         return maxLength;
    }
};