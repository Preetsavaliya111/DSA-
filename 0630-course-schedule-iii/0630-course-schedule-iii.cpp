class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int,int>>course;

        for(int i = 0 ; i < courses.size() ; i++){
            course.push_back({courses[i][1] , courses[i][0]});
        }

        sort(course.begin() , course.end());

        priority_queue<int>pq;
        int time = 0;

        for(int i = 0 ; i < course.size() ; i++){
            int deadline = course[i].first;
            int duration = course[i].second;

            time += duration;
            pq.push(duration);

            if(time > deadline){
                time = time - pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};