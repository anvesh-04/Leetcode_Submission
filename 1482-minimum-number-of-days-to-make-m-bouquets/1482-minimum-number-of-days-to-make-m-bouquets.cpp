class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) {
            return -1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans=high;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int count = 0;
            int val = 0;
            for(int i=0; i<bloomDay.size(); i++)
            {
                if(bloomDay[i]<=mid)
                {
                    val++;
                    if(val==k)
                    {
                        count++;
                        val=0;
                    }
                } 
                else
                {
                    val=0;
                }
            }
            if(count>=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};