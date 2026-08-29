class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int>f;

        for(char i : s){
            f[i]++;
        }

        struct cmp{
            bool operator()(pair<int , char>&a , pair<int , char>&b){
                if(a.first == b.first){
                return a.second < b.second;
                }

                return a.first < b.first;

            }
        };

        priority_queue<pair<int , char> , vector<pair<int , char>> , cmp>pq;

        for(auto i : f){
            char ch = i.first;
            int fq = i.second;
            pair<int , char>cur = {fq , ch};
            pq.push(cur);
        }

        int seat = 0;
        string res = "";
        while(!pq.empty()){
            pair<int , char>p = pq.top();
            pq.pop();

            if(seat == 0 || res[seat - 1] != p.second){
                res.push_back(p.second);
                seat++;

                p.first--;
                if(p.first > 0){
                    pq.push(p);
                }
            }

            else{
                if(pq.empty())return "";

                pair<int , char>p2 = pq.top();
                pq.pop();

                res.push_back(p2.second);
                seat++;

                p2.first--;
                if(p2.first > 0){
                    pq.push(p2);
                }
            pq.push(p);
            }

        }

        return res;
    }
};