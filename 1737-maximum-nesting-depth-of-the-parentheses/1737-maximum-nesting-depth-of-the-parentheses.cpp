class Solution {
public:
    int maxDepth(string s) {
        int ans  = 0;
        stack<char> stk;
        for(char c : s){
            if(c == '(') stk.push(c);
            else if(c == ')') stk.pop();
            ans = max(ans, (int)stk.size());
        }

        return ans;

    }
};