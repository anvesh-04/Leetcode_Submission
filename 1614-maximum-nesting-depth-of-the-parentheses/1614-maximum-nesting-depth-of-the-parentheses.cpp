class Solution {
public:
    int maxDepth(string s) {
        int brackOpen = 0;
        int ans = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(') brackOpen++;
            else if(s[i]==')') brackOpen--;
            ans = max(brackOpen, ans);
        }
        return ans;
    }
};