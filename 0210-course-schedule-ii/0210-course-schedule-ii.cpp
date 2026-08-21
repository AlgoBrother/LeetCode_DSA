class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1) { return {0};}

        vector<vector<int>> adj(numCourses);

        vector<int> indegree(numCourses, 0);
        for(auto &edge : prerequisites){
            int from = edge[0];
            int to = edge[1];
            adj[to].push_back({from});
            indegree[from]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i = 0; i < adj[node].size(); i++){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }

        if(ans.size() != numCourses) return{};
        return ans;




    }
};