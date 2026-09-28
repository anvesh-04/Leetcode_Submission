class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // Precompute the minimums from right to left
        vector<int> minSuffix(n);
        int mini = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            minSuffix[i] = mini;
        }

        // Calculate max on the fly from left to right
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            
            // The first time this is true, it is guaranteed to be the smallest index
            if (maxi - minSuffix[i] <= k) {
                return i; 
            }
        }
        
        return -1;
    }
};