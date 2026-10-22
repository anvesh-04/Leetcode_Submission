class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool peek = true;
        for(int i=0; i<nums.size(); i++)
            {
                if(nums[(i+1)%nums.size()]!= (nums[i]+1)%nums.size()) peek=false;
            }
        bool peek2 = true;
        for(int i=0; i<nums.size(); i++)
            {
               if(nums[(i+1)%nums.size()]!= (nums[i]-1+nums.size())%nums.size()) peek2=false;
            }
        int stop=0;
        if(peek==false && peek2==false) return -1;
        else
        {
                for(int i=0; i<nums.size(); i++)
                    {
                        if(nums[i]==0) stop=i;
                    }
        }
        int ans = 2e9; 
        
        if (peek == true) { 
            if (stop == 0) {
                ans = 0;
            } else {
                int leftShifts =stop;               
                int rightShifts = nums.size()-stop+2;
                ans=min(ans,min(leftShifts,rightShifts));
            }
        }
        if (peek2 == true) { 
            int reverseFirst = nums.size() - stop; 
            int shiftFirst = stop + 2;   
            ans = min(ans, min(reverseFirst, shiftFirst));
        }
        return ans;
    }
};
