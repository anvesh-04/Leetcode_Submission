class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low=*max_element(nums.begin(), nums.end());
        long long high=accumulate(nums.begin(), nums.end(),0LL); //0LL
        long long ans=high;
        while(low<=high)
        {
            long long mid = low+(high-low)/2;
            long long count=1;
            long long sum=0;
            for(int i=0; i<nums.size(); i++)
            {
                sum+=nums[i];
                if(sum>mid)
                {
                    count++;
                    sum=nums[i];
                }
            }
            if(count<=k)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};