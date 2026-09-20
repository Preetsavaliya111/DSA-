class Solution {
public:
    void generateParenthesis(int open , int close , int n , string &temp , vector<string>&res){
        if(open == n && close == n){
            res.push_back(temp);
            return;
        }

        //open
        if(open < n){
            temp.push_back('(');
            generateParenthesis(open + 1 , close , n ,  temp , res);
            temp.pop_back();
        }

        //close
        if(close < open){
            temp.push_back(')');
            generateParenthesis(open , close + 1 , n , temp , res);
            temp.pop_back();
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp = "";
        generateParenthesis(0 , 0 , n , temp , res);

        return res;
    }
};