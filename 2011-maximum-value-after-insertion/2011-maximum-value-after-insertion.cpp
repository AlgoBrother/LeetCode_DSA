class Solution {
public:
    string maxValue(string n, int x) {
        int ans = n.length();
        if(n[0] == '-'){
            for(int i = n.length(); i >= 1; i--){
                if(n[i] - '0' > x) ans = i;
            }
        }else{
            for(int i = n.length(); i >= 0; i--){
                if(n[i] - '0' < x) ans = i;
            }
        }

        n.insert(n.begin() + ans,  x + '0');
        return n;
    }
};