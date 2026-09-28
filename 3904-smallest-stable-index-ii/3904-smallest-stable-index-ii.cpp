class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxPrefix(nums.size());
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
            maxPrefix[i] = maxi;
        }
        int mini = INT_MAX;
        int smallestIndex = INT_MAX;
        for(int i=nums.size()-1; i>=0; i--)
        {
            mini = min(mini, nums[i]);
            if(maxPrefix[i]-mini<=k && smallestIndex>i) smallestIndex=i;
        }
        if(smallestIndex==INT_MAX) return -1;
        return smallestIndex;
    }
};