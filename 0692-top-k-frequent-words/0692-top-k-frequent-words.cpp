class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string , int>f;

        for(auto word : words){
            f[word]++;
        }

        struct cmp{
            bool operator()(pair<int , string>&a , pair<int , string>&b ){
                if(a.first == b.first){
                    return a.second < b.second;
                }
                return a.first > b.first;
            }
        };

        priority_queue<pair<int , string >, vector<pair<int , string>> , cmp >pq;
        
        for(auto i : f){
            string word = i.first;
            int freq = i.second;

            pair<int , string>cur = {freq , word};

            if(pq.size() < k){
                pq.push(cur);
                continue;
            }else if(pq.top().first > cur.first){
                continue;
            }else if(pq.top().first == cur.first && cur.second > pq.top().second) continue;
            else{
                pq.pop();
                pq.push(cur);
            }
        }

        vector<string>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin() , res.end());

        return res;
    }
};