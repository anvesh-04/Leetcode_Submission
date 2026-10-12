class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push('(');
            }
            else {
                // Case 1: We have "))"
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;  // consume the second ')'
                }
                // Case 2: We have only one ')'
                else {
                    ans++; // insert another ')'
                }

                // Now we have a complete "))"
                if (!st.empty()) {
                    st.pop(); // match with '('
                }
                else {
                    // No '(' available, so insert one
                    ans++;
                }
            }
        }

        // Every remaining '(' needs two ')'
        ans += st.size() * 2;

        return ans;
    }
};