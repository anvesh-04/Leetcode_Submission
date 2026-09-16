class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(), weights.end());
        int h=accumulate(weights.begin(), weights.end(), 0);  
        int ans=h;  
        while(l<=h)
        {
            int m = l+(h-l)/2;
            int count=1;
            int sum=0;
            for(int i=0; i<weights.size(); i++)
            {
                if(sum + weights[i] > m)
                {
                    count++;
                    sum = weights[i];
                }
                else
                {
                    sum += weights[i];
                }
            }
            if(count<=days)
            {
                ans=min(ans, m);
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};