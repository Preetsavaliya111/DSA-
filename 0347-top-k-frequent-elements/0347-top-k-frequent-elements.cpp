class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        struct cmp{
            bool operator()(pair<int , int>&a , pair<int , int>&b){
                if(a.first == b.first){
                    return a.second > b.second;
                }

                return a.first > b.first;
            }
        };
        priority_queue<pair<int , int> , vector<pair<int,int>> , cmp>pq;




        unordered_map<int , int>f;

        for(int i = 0 ; i < n ; i++){
            f[nums[i]]++;
        }



        for(auto i : f){
            int element = i.first;
            int freq = i.second;

            pair<int,int> cur = {freq , element};

            if(pq.size() < k){
                pq.push(cur);
                continue;
            }else if(cur.first < pq.top().first) continue;

            else{
                pq.pop();
                pq.push(cur);
            }
        }



        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;

    }
};