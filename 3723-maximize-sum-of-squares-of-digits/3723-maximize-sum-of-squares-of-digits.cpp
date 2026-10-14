class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        for(int i=0; i<num; i++){
            for(int j=9; j>=0; j--){
                if(sum>=j){
                    sum-=j;
                    ans+=to_string(j);
                    break;
                }
            }
        }
        if(sum) return "";
        return ans;
    }
};