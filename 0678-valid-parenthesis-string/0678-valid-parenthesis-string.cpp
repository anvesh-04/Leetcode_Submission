class Solution {
public:
    bool f(string &s, int i, int open, int close, vector<vector<vector<int>>> &dp){
        if(i==s.size()){
            if(open==close){
                return true;
            }
            return false;
        }
        if(dp[i][open][close]!=-1) return dp[i][open][close];
        bool val=false;
        bool sOpen=false;
        bool sClose=false;
        bool sNoChange=false;
        if(s[i]=='('){
            val = f(s, i+1, open+1, close, dp);
        }
        else if(s[i]==')')
        {
            if(close<open){
                val = f(s, i+1, open, close+1, dp);
            }
            else return false;
        }
        else{
            sOpen = f(s, i+1, open+1, close, dp);
            if(close<open) sClose = f(s, i+1, open, close+1, dp);
            sNoChange = f(s, i+1, open, close, dp);
        }
        return dp[i][open][close]=(sOpen || sClose || val || sNoChange);
    }
    bool checkValidString(string s) {
        vector<vector<vector<int>>> dp(s.size(), vector<vector<int>>(s.size(), vector<int>(s.size(), -1)));
        return f(s, 0, 0, 0, dp);
    }
};