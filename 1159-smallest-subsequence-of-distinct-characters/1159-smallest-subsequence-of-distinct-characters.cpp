class Solution {
public:
    string smallestSubsequence(string s) {
        string sol;
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;
        vector<bool> isAns(26, false);

        for(char c : s){
            while(!sol.empty() 
            && !isAns[c - 'a'] 
            && sol.back() > c
            && mp[sol.back()] > 0)
            {
                isAns[sol.back() - 'a'] = false;
                sol.pop_back();
            }

            mp[c]--;

            if(!isAns[c - 'a']) {
                isAns[c - 'a'] = true;
                sol.push_back(c);
            }
        }

        return sol;
    }
};