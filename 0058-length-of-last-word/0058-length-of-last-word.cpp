class Solution {
public:
    int lengthOfLastWord(string s) {

        auto new_s = unique(s.begin(), s.end(), [](char lhs, char rhs){
            return lhs == ' ' && rhs == ' ';
        });
        s.erase(new_s, s.end());

        if(!s.empty() && s.back() == ' '){
            s.pop_back();
        }

        if(!s.empty() && s.front() == ' '){
            s.erase(0, 1);
        }

        if(s.size() == 1) return 1;

        int size = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == ' ') break;
            size++;
        }

        return size;
    }
};