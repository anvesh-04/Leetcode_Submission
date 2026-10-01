class Solution {
public:
    int countCommas(int n) {    
        int count = n-1000+1;
        if(count<=0) return 0;
        return count;
    }
};