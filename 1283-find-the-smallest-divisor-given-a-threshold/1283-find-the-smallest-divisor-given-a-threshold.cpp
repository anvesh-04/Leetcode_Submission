class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=*max_element(nums.begin(), nums.end());
        int l=1;
        int high=ans;
        while(l<=high)
        {
            long long m=l+(high-l)/2;
            long long  count=0;
            for(int i=0; i<nums.size(); i++)
            {
                count+=(nums[i]+m-1)/m;
            }
            if(count<=threshold)
            {
                if(m<ans) ans=m;
                high=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};