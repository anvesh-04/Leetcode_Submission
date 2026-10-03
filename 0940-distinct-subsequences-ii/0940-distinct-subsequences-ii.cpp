class Solution {
public:
    long long MOD = 1e9+7;
    int f(string &s, vector<int> &nextSeen, int i, vector<int> &dp){
        if(s.size()==i){
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        int duplicates = 0;
        int total = (2*f(s, nextSeen, i+1, dp))%MOD;
        if(nextSeen[i]!=-1)
        {
            duplicates = f(s, nextSeen, nextSeen[i]+1, dp)%MOD;
        }
        total=(total-duplicates+MOD)%MOD;
        return dp[i]=total;
    }
    int distinctSubseqII(string s) {
        vector<int> nextSeen(s.size(), -1);
        vector<int> dp(s.size(), -1);
        unordered_map<char, int> mpp;
        for(int i=s.size()-1; i>=0; i--){
            if(mpp.find(s[i])!=mpp.end()){
                nextSeen[i]=mpp[s[i]];
            }
            mpp[s[i]]=i;
        }
        return (f(s, nextSeen, 0, dp)-1+MOD)%MOD;
    }
};