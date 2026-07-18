class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ys, others, xs;
        for(auto& c : s){
            if(c == x){
                xs += c;
            } 
            else if(c == y) ys += c;
            else others += c;
        }

    return ys + others + xs;
    
    }
};