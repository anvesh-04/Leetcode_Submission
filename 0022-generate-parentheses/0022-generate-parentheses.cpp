class Solution {
public:
    void f(int n, vector<string> & ans, string &res, int open, int close)
    {
        if(open==n && close==n){
            ans.push_back(res);
            return;
        }
        if(open<n)
        {
            res.push_back('(');
            f(n, ans, res, open+1, close);
            res.pop_back();
        }
        if(close<open){
            res.push_back(')');
            f(n, ans, res, open, close+1);
            res.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res = "";
        f(n, ans, res, 0, 0);
        return ans;
    }
};