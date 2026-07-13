class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int n = chars.size();

        for(int j = 0; j < n;){
            char current = chars[j];
            int count = 0;

            while(j < n && current == chars[j]){
                j++;
                count++;
            }

            chars[i++] = current;
            if(count > 1){
                string countStr = to_string(count);
                for(char c : countStr){
                    chars[i++] = c;
                }
            }

        }
        return i;
    }
};