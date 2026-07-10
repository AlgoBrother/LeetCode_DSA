class Solution {
public:
    string reverseWords(string s) {
        int read = 0;
        int write = 0;
        while(read < s.length()){
            while(read < s.length() && s[read] == ' '){
                read++;
            }

            while(read < s.length() && s[read] != ' '){
                s[write++] = s[read++];
            }

            while (read < s.length() && s[read] == ' ') read++;

            if(read < s.length()){
                s[write++] = ' ';
            }
           
        }
        s.resize(write);

        int left = 0;
        int right = s.length() -  1;
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
        int start = 0;

        for(int i = 0; i <= s.length(); i++){

            if(i == s.length() || s[i] == ' '){
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;




    }
};