class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=*max_element(piles.begin(), piles.end());
        int l=1;
        int high=ans;
        while(l<=high)
        {
            long long m=l+(high-l)/2;
            long long  count=0;
            for(int i=0; i<piles.size(); i++)
            {
                count+=(piles[i]+m-1)/m;
            }
            if(count<=h)
            {
                if(m<ans) ans=m;
                high=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};