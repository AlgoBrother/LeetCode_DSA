class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(auto& c : s){
            if(c == '(' || c == '{' || c == '['){
                stk.push(c);
                
            }else if(c == ')' || c == '}' || c == ']'){
                if(stk.empty()) return false;
                char top = stk.top();
                stk.pop();
                if(c == ')' && top != '(') return false;
                if(c == '}' && top != '{') return false;
                if(c == ']' && top != '[') return false;
            }
        }
        return stk.empty();
    }
};