class Solution {
public:
    
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0 , -1, 1};

    bool valid(int i, int j, int r, int c){
        return  i >= 0 && i < r && j>= 0 && j < c;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();

        int elem = image[sr][sc];

        if(elem == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = color; 
        while(!q.empty()){
            int current_q_size = q.size();
            while(current_q_size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int k = 0; k < 4; k++){
                    if(valid(i + row[k], j + col[k], r, c) &&
                        image[i + row[k]][j + col[k]] == elem){
                            image[i+row[k]][j+col[k]] = color;
                            q.push({i + row[k], j + col[k]});
                        }
                }
            }
        }
        return image;
    }

};