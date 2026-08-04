class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n= asteroids.size();

        for (int i = 0 ; i < asteroids.size() ; i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }else{
                while(!st.empty()  && st.top() > 0 && st.top() < -1*asteroids[i]){
                    st.pop();
                }
                if(st.empty() || st.top() < 0){
                st.push(asteroids[i]);
                }
                else if(!st.empty() && st.top() == -1*asteroids[i]){
                    st.pop();
                }
            }
        }
        int stz= st.size();
        vector<int>res(stz);
      for (int i = stz - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};