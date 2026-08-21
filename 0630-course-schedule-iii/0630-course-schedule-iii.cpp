class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        std::sort(
            courses.begin(), 
            courses.end(), 
            [](const vector<int>& a, const vector<int>& b){
                return a[1] < b[1];
            }
        );

        priority_queue<int> pq;
        int done = 0;
        for(auto &time : courses){
            int dur = time[0];
            int complete = time[1];

            done += dur;
            pq.push(dur);
            if(done > complete){
                done -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};