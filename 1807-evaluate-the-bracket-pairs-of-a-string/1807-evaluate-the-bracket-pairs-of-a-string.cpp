class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(int i=0; i<knowledge.size(); i++){
            mpp[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";

        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp.push_back(s[i]);
                    i++;
                }
                if(mpp.find(temp)!=mpp.end()){
                    ans+=(mpp[temp]);
                }
                else{
                    ans.push_back('?');
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};