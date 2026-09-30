class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
     int depthA=0; int depthB=0;
     vector<int> ans;
     for(int i=0; i<seq.size(); i++){
        if(seq[i]=='('){
            if(depthA<=depthB){
                depthA++;
                ans.push_back(0);
            }
            else{
                depthB++;
                ans.push_back(1);
            }
        }
        else{
            if(depthA>depthB){
                depthA--;
                ans.push_back(0);
            }
            else{
                depthB--;
                ans.push_back(1);
            }
        }
     }
    return ans;   
    }
};