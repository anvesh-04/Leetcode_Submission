class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       if(nums1[0]&1){
        int miniOdd = INT_MAX;
        int miniEven = INT_MAX;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]&1) miniOdd = min(miniOdd, nums1[i]);
            else miniEven = min(miniEven, nums1[i]);
        }
        if(miniOdd<miniEven) return true;
       }
       else{
        bool possible = true;
        int miniOdd = INT_MAX;
        int miniEven = INT_MAX;
        for(int i=0; i<nums1.size(); i++)
        {
            if(nums1[i]&1)
            {
                possible=false;
                miniOdd = min(miniOdd, nums1[i]);
            } 
            else{
                miniEven = min(miniEven, nums1[i]);
            }
        }
        if(possible)return true;
        else{
            if(miniOdd<miniEven)return true;
        }
       }
       return false;
    }
};