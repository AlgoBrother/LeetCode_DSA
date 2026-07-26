class Solution {
public:
    using l1 = long long;
    using T = tuple<l1, int, int, int>;
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        const l1 INF = 1e18;
        vector<vector<array<l1, 2>>> dist(m, vector<array<l1, 2>>(n, {INF, INF}));
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({1,0,0,0});
        dist[0][0][0] = 1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!pq.empty()){
            auto [d, x, y , p] = pq.top();
            pq.pop();

            if(d != dist[x][y][p]) continue;

            l1 nd = d + penalty[x][y];
            if(nd < dist[x][y][p ^ 1]){
                dist[x][y][p ^ 1] = nd;
                pq.push({nd, x, y, p ^ 1});
            }

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                bool allow;
                if(p == 0) allow = (dx[k] == 1 || dy[k] == 1);
                else allow = (dx[k] == -1 || dy[k] == -1);

                l1 cost = (l1)(nx + 1) * (ny + 1);
                if(!allow) cost += penalty[x][y];
                nd = d +cost;
                if(nd < dist[nx][ny][p ^ 1]){
                    dist[nx][ny][p ^ 1]=nd;
                    pq.push({nd, nx, ny, p ^ 1});
                }
            }
        }
        return min(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
    }
};