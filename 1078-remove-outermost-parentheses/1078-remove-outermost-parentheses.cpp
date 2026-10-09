class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int level = 0;
        for(auto &c : s){
            if(c & 1 ? --level : level++) result += c;
        }
        return result;
    }
};