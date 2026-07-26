class Solution {
public:
    int largestInteger(int n, int s) {
        if(s > 9 * n) return -1;
        if(s == 0) return 0;
        int k = 0;
        while (n--){
            if(s >= 9){
                k = k * 10 + 9;
                s -= 9;
            }else{
                k = k * 10 + s;
                s = 0;
            }
        }

        return k;
    }
};