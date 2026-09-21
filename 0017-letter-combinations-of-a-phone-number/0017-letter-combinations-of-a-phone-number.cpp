class Solution {
public:
    void letterCombinations(string digits , int n , int idx , string &diary , vector<string>&res , unordered_map<char , string>f ){
        if(idx == n){
            res.push_back(diary);
            return;
        }

        string choices = f[digits[idx]];

        for(int j = 0 ; j < choices.length() ; j++){
            diary.push_back(choices[j]);
            letterCombinations(digits , n , idx + 1 , diary , res , f);
            diary.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        int idx = 0;
        string diary;
        vector<string>res;
        unordered_map<char , string>f;

        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        letterCombinations(digits , n , idx , diary , res , f);
        return res;
    }
};