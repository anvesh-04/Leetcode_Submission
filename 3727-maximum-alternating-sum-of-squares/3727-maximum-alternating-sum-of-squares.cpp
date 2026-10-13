class Solution {
public:
    static bool comparator(int a, int b){
        return abs(a)<abs(b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comparator);
        long long sum=0;
        int n = nums.size();
        for(int i=0; i<n/2; i++){
            sum-=1LL*(nums[i]*nums[i]);
        }
        for(int i=n-1; i>=n/2; i--){
            sum+=1LL*(nums[i]*nums[i]);
        }
        return sum;
    }
};