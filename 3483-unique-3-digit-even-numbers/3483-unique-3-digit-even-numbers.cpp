class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> mpp;
        int ans=0;
        for(int i=0; i<digits.size(); i++){
            mpp[digits[i]]++;
        }

        for(int i=100; i<=998; i+=2){
            int hundreds = i/100;
            int tens = (i/10)%10;
            int ones = i%10;

            mpp[hundreds]--;
            mpp[tens]--;
            mpp[ones]--;

            if(mpp[hundreds]>=0 && mpp[tens]>=0 && mpp[ones]>=0) ans++;

            mpp[hundreds]++;
            mpp[tens]++;
            mpp[ones]++;
        }
        return ans;
    }
};